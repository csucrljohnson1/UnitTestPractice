/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZZ");
  ASSERT_EQ(2, actual);
}


TEST(PasswordTest, two_before_and_after)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZZaZZ");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, multiple_space)
{
  Password my_password;
  int actual = my_password.count_leading_characters("  jus tice");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_pass)
{
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, big_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  ASSERT_EQ(50, actual);
}

TEST(PasswordTest, odd_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("..........");
  ASSERT_EQ(10, actual);
}

TEST(PasswordTest, alternating_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("AAaaaAAAAAaaaa");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, mixed_case_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("AAaaaAAAAAaaaa");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, Upper_case_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("AA");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, lower_case_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_space_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("          ");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_symbol_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("!!!!!!!!!!");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_with_symbol_pass)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("!!!!aA    ");
  ASSERT_EQ(true, actual);
}
