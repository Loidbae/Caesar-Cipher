#include "pch.h"
#include "Coder.h"

int Coder::get_abc() const
{
	return abc_offset;
}

void Coder::set_abc(int abcproxy)
{
	abc_offset = abcproxy;
}
