#pragma once

#include <vector>
#include <iostream>
namespace kiln {
	struct DataSlice {
		int start_line;
		std::string body;
		int end_line;
	};

	struct PageLayout {
		std::vector<struct PageLayoutCol> col;
		std::vector<struct PageLayoutRow> row;

	};

	struct PageLayoutCol {
		float width;
		float height;
		float ratio = 1;
	};

	struct PageLayoutRow {
		float width;
		float height;
		float ratio = 1;
	};
}
