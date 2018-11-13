#include "ScalarBool.h"
#include <algorithm> // min, max
#include <cmath> // signbit

namespace ScalarBool {
	ScalarBool::ScalarBool(double init)
	{
		scalar = std::max(ScalarBool::MIN_CLAMP_VAL, std::min(init, ScalarBool::MAX_CLAMP_VAL));
	}

	double ScalarBool::GetVal()
	{
		return scalar;
	}

	// set the scalar to the maximum clamp
	void ScalarBool::Cap()
	{
		scalar = scalar < 0 ? MIN_CLAMP_VAL : MAX_CLAMP_VAL;
	}

	// returns the boolean value of the scalar defined as false if less than 0 and true if 0 or greater
	ScalarBool::operator bool() const
	{
		return std::signbit(scalar) == false;
	}

	// set scalar to a value, clamping between -1 and 1 if needed
	void ScalarBool::operator= (const double rval)
	{
		scalar = std::max(ScalarBool::MIN_CLAMP_VAL, std::min(rval, ScalarBool::MAX_CLAMP_VAL));
	}

	// given a boolean value, set scalar to 1 if true and -1 if false
	void ScalarBool::operator= (const bool rval)
	{
		scalar = rval ? MAX_CLAMP_VAL : -MIN_CLAMP_VAL;
	}

	// returns the flipped value of the scalar
	double ScalarBool::operator!()
	{
		return scalar * -1;
	}

	//sends the scalar value to an out stream
	std::ostream& operator<<(std::ostream &os, const ScalarBool& SB)
	{
		return os << SB.scalar;	
	}

	//invert the value of the scalar
	void ScalarBool::flip()
	{
		scalar *= -1;
	}
}
