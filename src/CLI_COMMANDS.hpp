#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

namespace kiln
{
	class CLICommands
	{
	public:
		// Makes the Setup Files for Kiln.
		static bool make(std::string path)
		{

			std::vector<std::string> paths = {
				"/public/",
				/*"/src/backend",*/
				"/src/data",
				"/src/frontend"};

			std::vector<bool> results;
			std::fstream output;

			for (const auto i : paths)
			{
				std::filesystem::path target = path + i;
				if (std::filesystem::create_directories(target))
				{
					std::cout << "Building: " << target << std::endl;
					results.push_back(true);
				}
				else
				{
					std::cout << "Failed to build: " << target << std::endl;
					results.push_back(false);
				}
			}

			output.open(path + "/fuel.txt", std::ios::out);
			if (output)
			{
				output << "# Welcome to Kiln! Define Variables Here!" << std::endl;
				output.close();
				std::cout << "Created 'fuel.txt'" << std::endl;
			}
			else
			{
				std::cout << "Failed to open file" << std::endl;
			}
			//Error and Result Checking
			for (auto r : results)
			{
				if (!r)
				{
					return false;
				}
			}
			
			return true;
		}
	};
}
