#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Operators.hpp"
#include "./datatypes/Line.hpp"
#include "clayfiles/html5.hpp"

namespace kiln {

	class FrontendFile {
	public:
		std::filesystem::path target_file;

		FrontendFile(std::filesystem::path target) {
			target_file = target;
			this->parse();
		}

		
		

	private:
		bool parse() {
			/*std::cout << "Rendering files..." << std::endl;*/
			bool results = false;

			
			
			std::ifstream file(this->target_file);

			if (file.is_open()) {
				std::string line;
				// This is how I parse each line of each file.
				std::vector<Line> document;
				int line_num = 1;
				while (getline(file, line)) {
					int lnum = 0;
					do {
						lnum++;
					} while (lnum < line.length());

					kiln::Line newline = {
						line_num,
						lnum,
						line
					};
					document.push_back(newline);
					line_num++;
				}

				auto first_line = kiln::Operators::tokenize(document[0].body, ' ');
				// Determines if required #pragma definition is found.
				if (first_line[0] == "#pragma") {
					// Determines what kind of files kiln will bake.
					if (first_line[1] == "html5") {
						kiln::HTML5 html5(document);
						html5.parse();
					}
					else {
						std::cerr << "Unsupported Pragma. | " << this->target_file << " Line: 1" << std::endl;
						exit(201);
					}
				}
				else {
					std::cerr << "No Pragma Found. | " << this->target_file << " Line: 1" << std::endl;
					exit(202);
				}

				file.close();
			}
			else {
				std::cerr << "Failed loading files" << std::endl;
			}

			return results;
		}

		
	};
}