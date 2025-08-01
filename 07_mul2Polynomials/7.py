import cmath

def transform(sequence, reverse=False):
    n = len(sequence)
    if n == 1:
        return

    seq_even = [sequence[2 * i] for i in range(n // 2)]
    seq_odd = [sequence[2 * i + 1] for i in range(n // 2)]

    transform(seq_even, reverse)
    transform(seq_odd, reverse)

    pi = cmath.pi
    angle = 2 * pi / n * (-1 if reverse else 1)
    root = cmath.exp(complex(0, angle))
    w = complex(1, 0)

    for i in range(n // 2):
        t = w * seq_odd[i]
        sequence[i] = seq_even[i] + t
        sequence[i + n // 2] = seq_even[i] - t
        if reverse:
            sequence[i] /= 2
            sequence[i + n // 2] /= 2
        w *= root

def poly_multiply(P, Q):
    n = 1
    while n < len(P) + len(Q):
        n <<= 1

    fP = [complex(P[i] if i < len(P) else 0, 0) for i in range(n)]
    fQ = [complex(Q[i] if i < len(Q) else 0, 0) for i in range(n)]

    transform(fP, False)
    transform(fQ, False)

    for i in range(n):
        fP[i] *= fQ[i]

    transform(fP, True)

    product = [round(fP[i].real) for i in range(n)]
    while len(product) >= (len(P) + len(Q)):
        product.pop()

    return product


poly1 = [2, 3, 5, 1]
poly2 = [4, 0, 1]
result = poly_multiply(poly1, poly2)
print(*result)