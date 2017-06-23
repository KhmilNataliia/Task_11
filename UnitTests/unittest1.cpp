#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "BoundedStackAggregatingArray.h"
#include "BoundedStackDerivedFromArray.h"
#include "PeekBackStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CASE("peekback_ex")
	{
		PeekbackStack<char> stack_(4);
		stack_.push('a');
		stack_.push('b');
		REQUIRE_THROWS(stack_.peekback(2, 'b'));
	};
	TEST_CASE("peekback")
	{
		PeekbackStack<char> stack_(4);
		stack_.push('a');
		stack_.push('a');
		REQUIRE(stack_.peekback(0, 'a'));
	};
	TEST_CASE("peekback2")
	{
		PeekbackStack<char> stack_(4);
		stack_.push('a');
		stack_.push('a');
		REQUIRE(stack_.peekback(0, 'b')==false);
	};

	TEST_CASE("bounded_stack_derived_from_array")
	{
		BoundedStackDerivedFromArray<char> stack(3);
		REQUIRE(stack.empty());
		stack.push('a');
		stack.push('a');
		stack.push('a');
		REQUIRE(stack.full());
		REQUIRE_THROWS(stack.push('a'));
		REQUIRE(stack.top() == 'a');
		stack.pop();
		stack.pop();
		stack.pop();
		REQUIRE(stack.empty());
		REQUIRE_THROWS(stack.pop());
		REQUIRE_THROWS(stack.top());
	};

	TEST_CASE("aggregating_array")
	{
		BoundedStackAgregatingArray<int> st(3);
		REQUIRE(st.empty());
	};

	TEST_CASE("aggregating_array3")
	{
		BoundedStackAgregatingArray<char> st(3);
		REQUIRE(st.size() == 3);
		st.push('a');
		REQUIRE(st.full() == false);
		st.push('a');
		st.push('b');
		REQUIRE(st.full() == true);
		REQUIRE_THROWS(st.push('a'));
		REQUIRE(st.top() == 'b');
		st.pop();
		st.pop();
		st.pop();
		REQUIRE(st.empty());
		REQUIRE_THROWS(st.pop());
		REQUIRE_THROWS(st.top());
	};
	
}