#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "Operators.hpp"


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
				while (getline(file, line)) {
					std::vector<std::string> statement;
					auto words = kiln::Operators::tokenize(line, ' ');
					for (auto word : words) {
						std::cout << word << std::endl;
						
					}
			
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