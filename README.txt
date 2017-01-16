Instructions for installing Brians interpolated and geom method for filtering 

You need Modular.cc (contains all the functions needed), Modular.h (contains header info) and code_to_put_in.cc (contains lines of code to call functions).


Add the functions from Modular.cc into MyCorrelator.cxx. Put the headers in Modular.h into MyCorrelator.h. (there is an include at the top that needs to be placed with the other included in MyCorrelator.h)

in code_to_put_in.cc, the top few lines are necessary global variables that need to be put into place. I placed mine near the top of MyCorrelator.cxx, right after 'using namespace std'.

In Abby's version of MyCorrelator, delete/ comment out  line 3868 to line 3886. In its place, take the code in code_to_put_in.cc in the section "For Use In PointThisEvent".

This should compile and run. God Willing.

