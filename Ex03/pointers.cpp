// test_pointers_references.cpp

#include <iostream>

int main(void)
{
  //
  // 1. floatへのポインタとして変数fを宣言する
  // 1. Declare a variable f as a pointer to a float
  std::cout << "1. Declare a variable f as a pointer to a float" << std::endl;
  float *f;
  // 2. float型の変数eを作成し、値2.71828fを格納する
  // 2. Create a float variable named e, and store the value 2.71828f
  std::cout << "2. Create a float variable named e, and store the value 2.71828f" << std::endl;
  float e = 2.71828f;
  // 3. fがeを指すようにする
  // 3. Make f points to e
  std::cout << "3. Make f points to e" << std::endl;
  f = &e;
  // 4. fが指すメモリの内容を出力する
  // 4. Print out the content of the memory location pointed to by f
  std::cout << "4. Print out the content of the memory location pointed to by f" << std::endl;
  std::cout << *f << std::endl;

  //
  short a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  // 5. short整数へのポインタとして変数ipを宣言する
  // 5. Declare a variable ip as a pointer to a short integer
  std::cout << "5. Declare a variable ip as a pointer to a short integer" << std::endl;
  short *ip;
  // 6. ipを配列aの先頭を指すようにする]
  // 6. Make ip points to the beginning of the array a
  std::cout << "6. Make ip points to the beginning of the array a" << std::endl;
  ip = a;
  // 7. ipが指す値とa[0]の内容が同じであることを確認する
  // 7. Print out what ip points to and the content of a[0] (verify they are the same
  std::cout << "7. Print out what ip points to and the content of a[0] (verify they are the same)" << std::endl;
  std::cout << "*ip = " << *ip << std::endl;
  std::cout << "a[0] = " << a[0] << std::endl;
  // 8. ipを3増やし、それがa[3]に対応している*ことを確認する
  // 8. Increase ip by 3 and check that what it points to corresponds to a[3]
  std::cout << "8. Increase ip by 3 and check that what it points to corresponds to a[3]" << std::endl;
  ip = ip + 3;
  std::cout << "*ip = " << *ip << std::endl;
  std::cout << "a[3] = " << a[3] << std::endl;
  // 9. ipを配列の最後の要素を指すようにする
  // 9. Make ip points to the last element of the array
  std::cout << "9. Make ip points to the last element of the array" << std::endl;
  ip = ip + 6;

  // 
  int n = 20;
  // 10. floatへのポインタとして変数faを宣言し、
  // 10. Declare a variable fa as a pointer to float and
  std::cout << "10. Declare a variable fa as a pointer to float and" << std::endl;
  float *fa;
  // ヒープ上に作成された長さが「n」の「float」型の配列を指すようにする
  // make it point to an array of ""n"" element of type ""float"" created on the heap
  std::cout << "make it point to an array of ""n"" element of type ""float"" created on the heap" << std::endl;
  fa = new float[n];
  // 11. この配列に、iが0からn-1までの値に対してi / 5.0fの値を格納する
  // 11. Store the values i / 5.0f for i from 0 to n-1 in this array
  std::cout << "11. Store the values i / 5.0f for i from 0 to n-1 in this array" << std::endl;
  for(int i = 0; i < n; i++){
    fa[i] = (float)i / 5.0f;
  }
  // 12. faの各要素を出力する
  // 12. Print out each element of fa
  std::cout << "12. Print out each element of fa" << std::endl;
  for(int i = 0; i < n; i++){
    std::cout << "fa[" << i << "] = " << fa[i] << std::endl;
  }
  // 13. 以前に割り当てられたメモリを解放する
  // 13. Delete the previously allocated memory
  std::cout << "13. Delete the previously allocated memory" << std::endl;
  delete fa;

  //
  int m = 5;
  n = 10;
  double** dd;
  // 14. ヒープ上にサイズがm * nの2次元配列のメモリを割り当てる（つまり、m個のn要素の配列）。
  // 14. Allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n
  std::cout << "14. Allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n)" << std::endl;
  double **arr = new double*[m];
  for(int i = 0; i < m; i++){
    arr[i] = new double[n];
  }
  // ddをこの2次元配列を指すようにする
  // Make dd points to this 2d array.
  std::cout << "Make dd points to this 2d array." << std::endl;
  dd = arr;
  // 15. dd[i][j]の要素をdouble(i)+double(j)+1に設定する
  // 15. Set the element dd[i][j] to be equal to double(i)+double(j)+1
  std::cout << "15. Set the element dd[i][j] to be equal to double(i)+double(j)+1" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dd[i][j] = double(i) + double(j) + 1;
        }
    }
  // 16. 2次元配列に割り当てられたメモリを解放する
  // 16. Delete the memory allocated for the 2d array
  std::cout << "16. Delete the memory allocated for the 2d array" << std::endl;
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;
  // 17. 変数f（1. の上記）への参照を作成する。名前をrfとする
  // 17. Create a reference to the variable f (1. above). Name it rf
  std::cout << "\n17. Create a reference to the variable f (1. above). Name it rf" << std::endl;
  float &rf = *f; 
  // 18. rfに値3.14159fを代入する
  // 18. Assign the value 3.14159f to rf
  std::cout << "18. Assign the value 3.14159f to rf" << std::endl;
  rf = 3.14159f;
  // 19. fとrfの値を出力し、それらが等しいことを確認する
  // 19. Print out the value of f and rf and verify that they are equal
  std::cout << "19. Print out the value of f and rf and verify that they are equal" << std::endl;
  std::cout << "f = " << *f << std::endl;
  std::cout << "rf = " << rf << std::endl;
  return 0;
}