def combine_polynomials(P1, P2, len1, len2):
    size = max(len1, len2)
    result = [0 for _ in range(size)]

    for i in range(len1):
        result[i] = P1[i]

    for i in range(len2):
        result[i] += P2[i]

    return result

def display_polynomial(poly, length):
    for i in range(length):
        print(poly[i], end="")
        if i != 0:
            print(f"x^{i}", end="")
        if i != length - 1:
            print(" + ", end="")
    print()


P1 = [3, 7, 2, 5]
P2 = [6, 1, 8]

len1 = len(P1)
len2 = len(P2)

print("Polynomial A:")
display_polynomial(P1, len1)

print("Polynomial B:")
display_polynomial(P2, len2)

merged = combine_polynomials(P1, P2, len1, len2)
final_len = max(len1, len2)

print("Resultant Polynomial:")
display_polynomial(merged, final_len)