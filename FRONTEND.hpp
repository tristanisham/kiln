#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Operators.hpp"
#include "Line.hpp"

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
			std::cout << "Rendering files..." << std::endl;
			bool results = false;

			
			
			std::ifstream file(this->target_file);

			if (file.is_open()) {
				std::string line;
				// Not sure where this library is... 
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

				for (auto s : document) {
					std::cout << s.num << " | " << s.len << " | " << std::endl;
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