# $\color{cadetblue}{\text{Problem 1}}$

## ${\color{darkkhaki}\text{Prob 1.1: }}{\color{olive}\text{ b}}$

```dafny
// x == y + 7  
......
// x == 11  
```

$\qquad \lbrace \space x == y + 7 \space \rbrace$  
$\qquad \quad \color{darkseagreen} (\space \text{prepare } x := x - y + 4\space)$  
$\qquad \lbrace \space x - y == 7 \space \rbrace$  
$\qquad \lbrace \space x - y + 4 == 11 \space\rbrace$  
$\quad \color{cornflowerblue} x := x - y + 4;$  
$\qquad \lbrace \space x == 11 \space \rbrace$  

&nbsp;

## ${\color{darkkhaki}\text{Prob 1.2: }}{\color{olive}\text{ c}}$

```java
// x == A && y == B 
......
// x == B - A && y == A + B 
```

$\qquad \lbrace \space x == A \space \land \space y == B \space \rbrace$  
$\qquad\quad \color{darkseagreen} (\space \text{prepare } y := x + y \space)$  
$\qquad \lbrace\space x == A \space\land\space x + y == A + B \space\rbrace$  
$\quad \color{cornflowerblue} y := x + y;$  
$\qquad \lbrace\space x == A \space\land\space y == A + B \space\rbrace$  
$\qquad\quad \color{darkseagreen} (\space \text{prepare } x := y - 2 * x \space)$  
$\qquad \lbrace\space y - 2 * x == A + B - 2 * A \space\land\space y == A + B \space\rbrace$  
$\quad \color{cornflowerblue} x := y - 2 * x;$  
$\qquad \lbrace \space x == B - A \space \land \space y == A + B \space \rbrace$  

&nbsp;

## ${\color{darkkhaki}\text{Prob 1.3: }}{\color{olive}\text{ b}}$

```java
// x == A && y == B 
.....
// x - y == A - B 
```

$\qquad \lbrace \space x == A \space \land \space y == B \space \rbrace$  
$\qquad \quad \color{darkseagreen} (\space \text{prepare } x := x + 1 \space)$  
$\qquad \lbrace \space x + 1 == A + 1 \space \land \space y == B \space \rbrace$  
$\quad \color{cornflowerblue} x := x + 1;$  
$\qquad \lbrace \space x == A + 1 \space \land \space y == B \space \rbrace$  
$\qquad \quad \color{darkseagreen} (\space \text{prepare } y := y + 1 \space)$  
$\qquad \lbrace \space x == A + 1 \space \land \space y + 1 == B + 1 \space \rbrace$  
$\quad \color{cornflowerblue} y := y + 1;$  
$\qquad \lbrace \space x == A + 1 \space \land \space y == B + 1 \space \rbrace$  
$\qquad \lbrace \space x - y == A - B \space \rbrace$  

&nbsp;

## ${\color{darkkhaki}\text{Prob 1.4: }}{\color{olive}\text{ a}}$

```java
// .....
y := x - y; x := x - y;
// x == A - B && y == B
```

$\qquad \lbrace \space x == A \space \land \space y == A - B \space \rbrace$  
$\qquad \quad \color{darkseagreen} (\space \text{prepare } y := x - y \space)$  
$\qquad \lbrace \space x == A \space \land \space x - y == A - (A - B) \space \rbrace$  
$\quad \color{cornflowerblue} y := x - y;$  
$\qquad \lbrace \space x == A \space \land \space y == B \space \rbrace$  
$\qquad \quad \color{darkseagreen} (\space \text{prepare } x := x - y \space)$  
$\qquad \lbrace \space x - y == A - B \space \land \space  y == B \space \rbrace$  
$\quad \color{cornflowerblue} x := x - y;$  
$\qquad \lbrace \space x == A - B \space \land \space y == B \space \rbrace$  

&nbsp;

## ${\color{darkkhaki}\text{Prob 1.5: }}{\color{olive}\text{ a}}$

```java
// .....
x := x + 3 * y + 5;
// 10 < x <= 16
```

$\qquad \lbrace \space 10 < 2 * x + 6 * y < 20 \space \rbrace $  
$\qquad \quad \color{darkseagreen} (\space \text{divide all sides by 2} \space)$  
$\qquad \lbrace \space 5 < x + 3 * y < 10 \space \rbrace $  
$\qquad \quad \color{darkseagreen} (\space \text{add 5 to all sides} \space)$  
$\qquad \lbrace \space 10 < x + 3 * y + 5 < 15 \space \rbrace $  
$\quad \color{cornflowerblue} x := x + 3 * y + 5;$  
$\qquad \lbrace \space 10 < x < 15 \space \rbrace $  
$\qquad \quad \color{darkseagreen} (\space \text{weakening} \space)$  
$\qquad \lbrace \space 10 < x \leq 16 \space \rbrace $  

&nbsp;

## ${\color{darkkhaki}\text{Prob 1.6: }}{\color{olive}\text{ a}}$

```java
// .....
z, x, y := x - y, x + y + z, z - y; 
//  x == A + B && y == 3 * B - A
```

$\qquad \lbrace \space  x + y + z == A + B \space \land \space z - y == 3 * B - A \space \rbrace$  
$\quad \color{cornflowerblue} z, \space x, \space y := x - y, \space x + y + z,\space z - y;$  
$\qquad \lbrace \space x == A + B \space \land \space y == 3 * B - A \space \rbrace$  

