#include "check_convert.h"
#include <check.h>

START_TEST(test_convertSingleRomanNumeralCharToInt)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("I"), 1);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_VI)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("VI"), 6);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_MJ)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("MJ"), -1);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_JM)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("JM"), -1);
}
END_TEST

START_TEST(test_subtractIfNextCharIsSmallerThanCurrentChar_IX)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("IX"), 9);
}
END_TEST

START_TEST(test_convertRomanNumeralString_detectBadSubtractionPair_IC)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("IC"), -1);
}
END_TEST


START_TEST(test_convertRomanNumeralString_dealsWithIncorrectInput_CMIIII)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("CMIIII"), -1);
}
END_TEST


START_TEST(test_convertRomanNumeralString_dealsWithIncorrectInput_MCMCIX)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("MCMCIX"), -1);
}
END_TEST

START_TEST(test_convertRomanNumeralString_dealsWithIncorrecitInput_IIII)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("IIII"), -1);
}
END_TEST

START_TEST(test_convertRomanNumeralString_dealsWithNumeralStringGreaterThan_3999)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("MMMM"), -1);
}
END_TEST

START_TEST(test_convertIntToRomanNumeralString)
{

	ck_assert_int_eq(convertIntToRomanNumeralString(3999, "MMMCMXCIX"), "MMMCMXCIX");
}
END_TEST

Suite * convert_suite(void)
{
	Suite *s;
	TCase *tc_convert;

	s = suite_create("Convert");

	tc_convert = tcase_create("Core");

	tcase_add_test(tc_convert, test_convertSingleRomanNumeralCharToInt);

	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_VI);

	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_MJ);
	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_JM);

	tcase_add_test(tc_convert, test_subtractIfNextCharIsSmallerThanCurrentChar_IX);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_detectBadSubtractionPair_IC);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_dealsWithIncorrectInput_CMIIII);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_dealsWithIncorrectInput_MCMCIX);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_dealsWithIncorrecitInput_IIII);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_dealsWithNumeralStringGreaterThan_3999);

	tcase_add_test(tc_convert, test_convertIntToRomanNumeralString);

	suite_add_tcase(s, tc_convert);

	return s;
}
