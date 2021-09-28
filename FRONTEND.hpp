#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>



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

			std::vector<std::string> lines;
			
			std::ifstream file(this->target_file);

			if (file.is_open()) {
				std::string line;
				// Not sure where this library is... 
				// This is how I parse each line of each file.
				while (getline(file, line)) {
					std::cout << line << std::endl;
					lines.push_back(line);

				}
			}
			else {
				std::cout << "Failed loading files" << std::endl;
			}

			return results;
		}
	};
}