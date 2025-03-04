#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selection_sort.h"  // Include the header file

START_TEST(test_selection_sort_basic) {
    int arr[] = {64, 25, 12, 22, 11};
    int expected[] = {11, 12, 22, 25, 64};
    selectionSort(arr, 5);
    ck_assert_mem_eq(arr, expected, sizeof(expected));
}
END_TEST

START_TEST(test_selection_sort_reverse) {
    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    selectionSort(arr, 5);
    ck_assert_mem_eq(arr, expected, sizeof(expected));
}
END_TEST

Suite *selection_sort_suite(void) {
    Suite *s;
    TCase *tc_core;
    s = suite_create("SelectionSort");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_selection_sort_basic);
    tcase_add_test(tc_core, test_selection_sort_reverse);
    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = selection_sort_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
