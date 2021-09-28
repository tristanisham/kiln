#pragma once
#include "inja.hpp"
#include "FRONTEND.hpp"

namespace kiln {
	class Parser {
	public:
		
		std::vector<FrontendFile> graphics;
		Parser() {
			this->iter_frontend();
		}
		

	private:
		void iter_frontend() {
			std::filesystem::path cwd = std::filesystem::current_path();
			if (std::filesystem::exists(cwd / "frontend")) {
				std::cout << "Reading frontend clay files.." << std::endl;
				for (const auto& i : std::filesystem::recursive_directory_iterator(cwd / "frontend")) {

					
					const auto filenameStr = i.path().filename().string();

					if (i.is_regular_file()) {
						FrontendFile file(i.path());
						 
					}
					else {
						std::cout << "Invalid File: " << filenameStr << '\n';

					}
				}
					/*std::cout << i << std::endl;
					FrontendFile file(i.path());*/
				
			}
			else {
				std::cout << "Please initialize a directory and 'cd' into it using the 'setup' command" << std::endl;
			}
			
		}
	};
}