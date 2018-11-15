#pragma once
#include <iostream>

namespace ScalarBool {
	/* ScalarBool is a data type that contains a floating point number
	(default double) bounded between -1 and 1. It evaluates to false when
	the value is less than zero and true if it is positive.
	*/
	class ScalarBool
	{
	public:
		ScalarBool(void);
		double GetVal(void);
		void cap(void);
		operator bool() const;
		void operator=(const double);
		void operator=(const bool);
		double operator!();
		friend std::ostream& operator<<(std::ostream &out, const ScalarBool& SB);
		void flip();
	private:
		double scalar;
		const double MIN_CLAMP_VAL = -1.0;
		const double MAX_CLAMP_VAL = 1.0;
	};
}