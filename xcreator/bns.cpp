#include "main.h"

struct bns_i {
	
	char	signature[4];
	char	version[4];

	bns_i() {
		strcmp(signature, "BNS");
		strcmp(version, "0.1");
	}

	operator bool() const {
		return strcmp(signature, "BNS") == 0 && getversion() <= 0 && getsubversion() <= 1;
	}

	int getversion() const {
		return version[0] - '0';
	}

	int getsubversion() const {
		return version[2] - '0';
	}

};