# CPSC350_SP21_ASSIGNMENT3_BOHLINGER

Jason Bohlinger
2364725

PastGenerations::move function found from StackOverflow: https://stackoverflow.com/questions/        45447361/how-to-move-certain-elements-of-stdvector-to-a-new-index-within-the-vector


The PastGenerations class has a private vector that holds pointers to Grid objects.
    The "current" generation is kept at the last position of the vector, and the oldest 
    generation is kept as position 0. Modifying the oldest (and now unneeded) Grid is
    is done by moving it to the end of the vector and making the necessary modifications
    based on the average neighbor counts of the prior 3 grids.

