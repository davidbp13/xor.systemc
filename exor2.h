#pragma once

#include "systemc.h"
#include "nand2.h"

// TODO: implement EXOR module here using only nand2 components
// inputs: bool A, B
// output bool F
SC_MODULE(exor2)          // declare nand2 sc_module
{
  sc_in<bool> A, B;       // input signal ports
  sc_out<bool> F;         // output signal ports
  nand2 n1, n2, n3, n4;
  sc_signal<bool> s1, s2, s3;

  SC_CTOR(exor2) : n1("n1"), n2("n2"), n3("n3"), n4("n4"),           // constructor for exor2
                   s1("s1"), s2("s2"), s3("s3"),
                   A("A"), B("B"), F("F")
  {
    n1.A.bind(A);
    n1.B.bind(B);
    n1.F.bind(s1);

    n2.A.bind(A);
    n2.B.bind(s1);
    n2.F.bind(s2);

    n3.A.bind(s1);
    n3.B.bind(B);
    n3.F.bind(s3);

    n4.A.bind(s2);
    n4.B.bind(s3);
    n4.F.bind(F);
    //sensitive << A << B;  // sensitivity list
  }
};
