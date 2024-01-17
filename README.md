# Problem - równanie transportu ciepła
## Równanie
$$
-k(x)u''(x)=0
$$
$$
u(2)=3
$$
$$u'(0)+u(0)=20$$
$$
k(x) =
  \begin{cases}
    1       & \quad \text{dla } x \in [0,1]\\
    2  & \quad \text{dla } x \in (1,2]
  \end{cases}
$$
## Sformułowanie wariacyjne
$$
\forall_{x \in [0,2]} \text{ }k(x)\neq0 
$$
$$-k(x)u''(x) = 0 \text{ /:}(-k(x))$$
$$u''(x)=0$$
Jako, że z prawej strony dziedziny występuje warunek Dirichleta, funkcja bazowa v przyjmuje tam wartość 0.
$$\int_0^2 u''vdx=0 \text{, } \forall_v \text{ } v(2)=0$$
Lewą stronę równania scałkowano przez części.

$$[u'v]^2_0 - \int_0^2 u'v'dx=0$$
$$u'(2)v(2)-u'(0)v(0)-\int_0^2 u'v'dx = 0$$
Jako, że $v(2) = 0$:
$$-u'(0)v(0)-\int_0^2u'v'dx=0$$
Korzystając z warunku Cauchy'ego $u'(0)+u(0)=20$:
$$-(20-u(0))v(0) - \int_0^2u'v'dx=0$$
$$-20v(0)+u(0)v(0) = \int_0^2u'v'dx$$
$$u(0)v(0) - \int_0^2u'v'dx = 20v(0)$$
Można wprowadzić oznaczenia:
$$B(u,v) = u(0)v(0) - \int_0^2u'v'dx$$
$$L(v) = 20v(0)$$
Wtedy:
$$B(u,v) = L(v)$$
## Rozszerzenie warunku brzegowego

Na prawym brzegu ustalony jest niezerowy warunek Dirichleta. W takim razie stosuje się przesunięcie:
$$u = w + \tilde{u}$$
gdzie $\tilde{u}$ to dowolna funkcja spełniająca równanie:
$$\tilde{u}(2)=3$$

Tymczasem jeśli chodzi o funkcję w:
$$w(2)=0$$
Wstawiając równanie $u = w + \tilde{u}$ do sformułowania wariacyjnego:
$$B(w + \tilde{u}, v) = L(v)$$
$$B(w,v) + B(\tilde{u},v) = L(v)$$
$$B(w,v) = L(v) - B(\tilde{u},v) = L'(v)$$

## Konstrukcja podprzestrzeni elementów skończonych $V_h$

Dziedzinę dzieli się na n równych części, tak że $h = \frac{2}{n}$. $x_{k+1} = x_k + h$, $x_{k-1}=x_k = h$, dla $k=1,2, 3, ..., n-1$. Wektory bazowe poza brzegiem:

$$e_k(x) =
  \begin{cases}
    \frac{x-x_{k-1}}{h}       & \quad \text{dla } x \in [x_{k-1}, x_k]\\
    \frac{x_{k+1}-x}{h}  & \quad \text{dla } x \in [x_k, x_{k+1}]\\
    0 & \quad \text{w przeciwnym przypadku}
  \end{cases}
$$
Wektor bazowy na brzegu:
$$e_0(x) =
  \begin{cases}
    \frac{x_{1}-x}{h}  & \quad \text{dla } x \in [x_0, x_1]\\
    0 & \quad \text{w przeciwnym przypadku}
  \end{cases}
$$

Wektor bazowy na prawym brzegu ($e_n(x)$) jest równy 0, bo $w(2) = 0$ oraz $v(2) = 0$.

## Funkcja $\tilde{u}(x)$
Jako, że $\tilde{u}(2) = 3$, można przyjąć następującą postać funkcji:
$$\tilde{u}(x) =
  \begin{cases}
    3\frac{x-x_{n-1}}{h}       & \quad \text{dla } x \in [x_{n-1}, x_n]\\

    0 & \quad \text{w przeciwnym przypadku}
  \end{cases}
$$

## Aproksymacja $w(x)$
### Problem oryginalny:
Znaleźć $w \in V$ spełniające:
$$
B(w,v)=L'(v), \forall v\in V
$$
### Problem przybliżony:
Dla $V_h \subset V$ znaleźć $w \in V_h$ spełniające:

$$ 
B(w_h, v_h) = L'(v_h), \forall v_h \in V_h
$$
Przyjmuje się aproksymację w:
$$w \approx w_h = \sum_{i=1}^n w_ie_i$$
Takie w można podstawić do równania:
$$
B(\sum_{i=1}^n w_ie_i, v_j) = L'(v_j) \text{ dla } v_j=e_j \text{ dla } j=1,2,3,...,n$$
Można $w_i$ wyciągnąć przed nawias

$$
\sum_{i=1}^n w_i B(e_i,e_j) = L'(e_j)
$$
Powstaje układ równań, który ma postać:

$$
\begin{bmatrix}
  B(e_1,e_1) & B(e_1,e_2) & \cdots & B(e_1,e_n) \\
  B(e_2,e_1) & B(e_2,e_2) & \cdots & B(e_2, e_n) \\
  \vdots  & \vdots  & \ddots & \vdots  \\
  B(e_n,e_1) & B(e_n,e_2) & \cdots & B(e_n,e_n)
 \end{bmatrix}
 \begin{bmatrix}
 w_1 \\
 w_2 \\
 \vdots \\
 w_n
 \end{bmatrix}
 =
  \begin{bmatrix}
 L'(e_1) \\
 L'(e_2) \\
 \vdots \\
 L'(e_n)
 \end{bmatrix}
 $$