#pragma once
#include "inja.hpp"
#include "FRONTEND.hpp"
#include <vector>

namespace kiln {
	class Parser {
	public:
		
		std::vector<FrontendFile> graphics;
		Parser() {
			this->iter_frontend();
		}
		
		


	private:
		/// <summary>
		/// Iterates through frontend files, parsing each and writing results to public/$filename.html
		/// </summary>
		void iter_frontend() {
			//Current Working Directory
			std::filesystem::path cwd = std::filesystem::current_path();
			if (std::filesystem::exists(cwd / "fuel.txt")) {
				// Base dir the program needs to run from.
				std::filesystem::path base_dir = cwd;
				if (std::filesystem::exists(cwd / "src/frontend")) {
					// Filesystem directory
					std::filesystem::path frontend = base_dir / "src/frontend";
					std::cout << "Reading clay files..." << std::endl;
					for (const auto& i : std::filesystem::recursive_directory_iterator(frontend)) {


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
					std::cerr << "Unable to find frontend folder. Please reinitialize src directory." << std::endl;
					exit(102);
				}
			}
			else {
				std::cerr << "Please initialize a directory and 'cd' into it using the 'setup' command" << std::endl;
				exit(101);
			}
			
		}
	};
}