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
			DataSlice layout = parse_layout();
			parse_layout_string(layout);
		}

	private:
		DataSlice parse_layout() {
			DataSlice layout_slice = { NULL, "", NULL };
			for (auto line : this->doc) {
				auto words = Operators::tokenize(line.body, ' ');


				//std::cout << word << "(" << line.num << ")" << ", ";
				if (words.size() == 1) {

					if (layout_slice.start_line != NULL) {
						if (words[0] == "~/layout~" && words.size() == 1) {
							layout_slice.end_line = line.num;
						}
					}
					else {

						if (words[0] == "~layout~" && words.size() == 1) {

							layout_slice.start_line = line.num;


						}

					}

				}




			}

			for (int s = layout_slice.start_line; s < layout_slice.end_line - 1; s++) {
				layout_slice.body += this->doc[s].body;
			}

			return layout_slice;
		}

		void parse_layout_string(DataSlice layout) {
			int c_pos = 0;
			DataSlice pure_slice = { 0,"",0 };
			// Builds the slice matrix for purifying the slice.
			for (auto c : layout.body) {
				if (c == '|' || c == '_') {
					if (pure_slice.start_line == NULL) {
						pure_slice.start_line = c_pos;
					}
					else {
						pure_slice.end_line = c_pos;
					}
				}

				c_pos++;
			}

			std::cout << pure_slice.start_line << " | " << pure_slice.end_line << std::endl;
		}
	};
}