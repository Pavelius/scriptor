#include "crt.h"

#pragma once

// Auto grow simple class. Primary use for custom allocators.
// No destructor!! When program exit atexit() may destroy allocator object
// before any static instance of this class.
template<typename T, int max_count = 4096>
struct agrw
{
	T		data[max_count];
	int		count;
	agrw*	next;
	
	agrw() : next(0), count(0) {
	}
	
	T* add() {
		auto t = this;
		while(t->count >= max_count) {
			if(!t->next)
				t->next = new autogrow();
			t = t->next;
		}
		return t->data + t->count++;
	}

	// Clear all elemnts in collection
	void clear() {
		auto z = next;
		while(z) {
			auto n = z->next;
			z->next = 0;
			delete z;
			z = n;
		}
		next = 0;
		count = 0;
	}

	T* begin() { return data; }

	T* end() { return data + count; }

};