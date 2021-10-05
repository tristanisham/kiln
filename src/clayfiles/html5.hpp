#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../datatypes/Line.hpp"
#include "../Operators.hpp"
#include "data_selection.hpp"

namespace kiln {
	class HTML5 {
	public:
		std::vector<Line> doc;

		HTML5(std::vector<Line> doc) {
			this->doc = doc;
		}

		void parse() {
			std::cout << "Made it to here!" << std::endl;
			DataSlice layout_slice;

			for (auto line : this->doc) {
				auto words = Operators::tokenize(line.body, ' ');
								
				if (words[0] == "~layout~" && words.size() <= 1) {
					layout_slice.start_line = line.num;
				}
				else if (words[0] == "~/layout~" && words.size() <= 1) {
					if (layout_slice.start_line != NULL) {
						layout_slice.end_line = line.num;
					}
				}
				
			}

			for (int s = layout_slice.start_line; s < layout_slice.end_line - 1; s++) {
				layout_slice.body += this->doc[s].body;
			}

			std::cout << layout_slice.body << std::endl;
		}

	private:
		void create_layout(DataSlice slice) {

		}
	};
}