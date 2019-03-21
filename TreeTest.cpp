/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  ariel::Tree increasetree; //tree for increasing-order checks and tests for all combinations of binary tree test cases.
  ariel::Tree negativetree;  //tree for decreasing-order with NEGATIVE integers checks and tests for all combinations of binary tree test cases.

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

//Added tests:
  .check_equal (increasetree.size(), 0) //new tree should have size zero.
  .check_ok (increasetree.insert(0)) //inserting integers in increasing order. tree should be as follows:
  //                                    0
  .check_ok (increasetree.insert(1)) //   1
  .check_ok (increasetree.insert(2)) //     2
  .check_ok (increasetree.insert(3)) //       3
  .check_equal (increasetree.size(), 4) //tree size should be 4. we inserted 4 elements.
  .check_throws (increasetree.parent(0)) //there should be no parent for node "0".
  .check_equal (increasetree.parent(1),0) //parent of element "1" should be the root, a.k.a  "0".
  .check_throws (increasetree.left(3)) //there are no childs for node "3".
  .check_throws (increasetree.right(3)) //there are no childs for node "3".
  .check_throws (increasetree.left(0)) //there are no left-childs for the root "0".
  .check_equal (increasetree.right(0),1) //there right child of root node "0" should be "1".
  .check_equal (increasetree.getSize(),4) //function "getSize" should return 4.
  .check_ok (increasetree.find(2)) //function "find" should pass as "2" is inside the tree.
  .check_throws (increasetree.find(0)) //function "find" should fail as "0" is NOT inside the tree.
  .check_ok (increasetree.root()) //function "root" should pass as there is a root for the tree.

  .check_ok (negativetree.insert(-1)) //adding negative integers in degreasing order.
  .check_ok (negativetree.insert(-2))
  .check_ok (negativetree.insert(-3))
  .check_equal (negativetree.size(),3)  //size should be 3
  .check_equal (negativetree.left(-1),-2)  //left child of ROOT ("-1") node should be "-2"
  .check_equal (negativetree.left(-2),-3) //left child of INSIDE_NODE("-2") node should be "-3"
  .check_ok (negativetree.insert(0)) //we now insert a larger-than-every-node "0" to the tree.
  .check_equal (negativetree.parent(0),-1) //parent of the "0" node, which we inserted last, should be the right chile of -1. thus, parent of 0 is -1.
  .check_equal (negativetree.right(-1),0) //explained above
  .check_throws (negativetree.left(0)) //last-inserted node "0" should have no childs!
  .check_throws (negativetree.right(0)) //last-inserted node "0" should have no childs!

  .check_throws (negativetree.parent(-1))

  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
