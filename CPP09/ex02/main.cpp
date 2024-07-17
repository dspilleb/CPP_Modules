#include "PmergeMe.hpp"

#include <cassert>
bool test_Dichotomic_insertion_Vector( void )
{
	std::vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(10);
	
	// test insertion at start
    // Test insertion at start
    std::vector<int>::iterator it = v.begin();
    Dichotomic_insertion_Vector(v, 1); // Insert 1 at the beginning
    std::cout << "After inserting 1 at start: ";
    print_container(v.begin(), v.end());
    assert(v[0] == 1 && v[1] == 2 && v[2] == 4 && v[3] == 8 && v[4] == 10);

    // Test insertion at end
    it = v.end();
    Dichotomic_insertion_Vector(v, 12); // Insert 12 at the end
    std::cout << "After inserting 12 at end: ";
    print_container(v.begin(), v.end());
    assert(v[0] == 1 && v[1] == 2 && v[2] == 4 && v[3] == 8 && v[4] == 10 && v[5] == 12);

    // Test insertion in the middle (1)
    it = v.begin() + 3; // Position to insert 6 between 4 and 8
    Dichotomic_insertion_Vector(v, 6);
    std::cout << "After inserting 6 in the middle: ";
    print_container(v.begin(), v.end());
    assert(v[0] == 1 && v[1] == 2 && v[2] == 4 && v[3] == 6 && v[4] == 8 && v[5] == 10 && v[6] == 12);

    // Test insertion at a random place
    it = v.begin() + 2; // Position to insert 3 between 2 and 4
    Dichotomic_insertion_Vector(v, 3);
    std::cout << "After inserting 3 at a random place: ";
    print_container(v.begin(), v.end());
    assert(v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 6 && v[5] == 8 && v[6] == 10 && v[7] == 12);

    std::cout << "All assertions passed!" << std::endl;
	return (true);
	// test insertion at end
	// test insertion middle 1
	// test insertion random place
}

int main (int ac, char **av)
{
	std::vector<int> v;
	std::list<int> l;

	if (ac <= 1)
	{
		std::cerr << ERR_ARG << std::endl;
		return (-1);
	}
	if (!parse_args(v, l, ac, av)){};
		// return (-1);
	print_container(v.begin(), v.end());
	v = Merge_Insertion_Sort_Vector_util(v);
	print_container(v.begin(), v.end());
	// int value = 2;
	// Dichotomic_insertion_Vector(v, value);
	// std::cout << "after : " << std::endl;
	// print_container(v.begin(), v.end());
	// print_container(l.begin(), l.end());
	// test_Dichotomic_insertion_Vector();
	// Parse arguments as integers
	// sort
	// measure time
	return (0);

}