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
			DataSlice layout_slice = { 0,"",0 };
			std::cout << layout_slice.start_line << layout_slice.end_line << std::endl;
			for (auto line : this->doc) {
				auto words = Operators::tokenize(line.body, ' ');

				if (layout_slice.start_line != NULL) {
					
				}
				else {
					
					if (words[0] == "~layout~" && words.size() <= 1) {
						layout_slice.start_line = line.num;
					}
					else if (words[0] == "~/layout~" && words.size() <= 1) {
						if (layout_slice.start_line != NULL) {
							layout_slice.end_line = line.num;
						}
					}

					for (int s = layout_slice.start_line; s < layout_slice.end_line - 1; s++) {
						layout_slice.body += this->doc[s].body;
					}

					
				}
				
			}

			std::cout << layout_slice.body << std::endl;

			
		}

	private:
		void create_layout(DataSlice slice) {

		}
	};
}