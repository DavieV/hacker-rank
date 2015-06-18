from collections import defaultdict

primes = {
    'a' : 2,
    'b' : 3,
    'c' : 5,
    'd' : 7,
    'e' : 11,
    'f' : 13,
    'g' : 17,
    'h' : 19,
    'i' : 23,
    'j' : 29,
    'k' : 31,
    'l' : 37,
    'm' : 41,
    'n' : 43,
    'o' : 47,
    'p' : 53,
    'q' : 59,
    'r' : 67,
    's' : 71,
    't' : 73,
    'u' : 79,
    'v' : 83,
    'w' : 89,
    'x' : 97,
    'y' : 101,
    'z' : 103
}

def summation(n):
    return (n * (n - 1)) / 2

def get_key(s):
    prod = 1;
    for c in s:
        prod *= primes[c]
    return prod

def count_pairs(s):
    anagrams = {}
    anagrams = defaultdict(lambda: 0, anagrams)
    for i in range(0, len(s)):
        for j in range(i, len(s)):
            anagrams[get_key(s[i:j+1])] += 1

    pairs = 0
    for k in anagrams:
        pairs += summation(anagrams[k])

    return pairs

t = input()
for i in range(0, t):
    s = raw_input()
    print count_pairs(s)
