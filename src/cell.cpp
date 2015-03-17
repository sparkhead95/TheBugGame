#include <vector>
#include "cell.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//                                Cell.

//             cell holds an aphid vector and a ladybug vector.

cell::cell() {
	vector<Aphid> cellAphids;
	vector<Ladybug> cellLadys;
}

string cell::AphidPresent() {
	string twat = "";
//	This function returns a string depending on whether there's an aphid present

//	if there is, return "A:"
//	else "-:"
	return twat;
}

string cell::LadybugPresent() {
//	same as the aphid one

}

string GetCellContents() {
//	This function returns a string as the following:
	("|" && cellAphids.size() && AphidPresent() && ":" && LadybugPresent()
			&& cellLadys.size() && "|")

}
