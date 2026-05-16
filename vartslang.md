i32 y <- 0;
i32 $p1 <- &y;
i32 $$p2 <- &p1;

<-[]->{i32} list;
<-[]->{i32} list1 <- []{2};
<-[]->{i32} list2 <- []{2} -> {2,2};

<-[]->{i32} list <- []{2} -> {2,2};
<-[]->{i32} list1 <- []{2};



<-[]->{i32,i32} list2 <- []{2,2} -> {{23,2},{23,23}};

?{y == 3 \/ x ==3} -> {
    y <- 9;
} -> ?{y == 2 /\ x==2} -> {
    y <- 3;
} -> {
    y <- 0;
}

<-@->{i32} name <- @{i32 x <- 0, i32 y <- 6} -> {
    ^ x + y; 
}

<-@->{i32} func1 <- @{i32 x} -> x*2;

// funcion main call
i32 newvar <- name <| {2,4};

<-?->{ i32 i <- 0; i> 33; i++} -> {
    //code
}

<-?->{;name != "artumus";} -> {
    //code  
}

{
    //code
} -> <-?->{;name!="artermus";}

<-:->{i32 value <-: list} -> {

}

struct user <- {
    i32 name <- 32;
    i32 class <- 3;
    i32 play <- 32;
}
#=> comment
enum name <- {
    up,
    down,
    right,
    left,
}
