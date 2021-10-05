#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace kiln {
	class Operators {
	public:
		static std::vector<std::string> tokenize(std::string const& target, const char deliminator) {
			size_t start;
			size_t end = 0;

			std::vector<std::string> results;

			while ((start = target.find_first_not_of(deliminator, end)) != std::string::npos) {
				end = target.find(deliminator, start);
				results.push_back(target.substr(start, end - start));
			}

			return results;
		}
	};

}