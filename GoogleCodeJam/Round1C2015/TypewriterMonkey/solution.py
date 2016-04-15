# Find the maximum amount of overlap. We can just try
# every possible amount and check which ones work.
def max_overlap(t):
  for i in range(1, len(t)):
    if t[i:] == t[0:len(t)-i]:
      return len(t) - i
  return 0

# Returns the probability of the target word
# occurring at a fixed place.
def probability(target, keyboard):
  P = 1.0
  # Compute the product of the probabilities 
  # for each letter of the word being correct.
  for i in range(len(target)):
    # The probability for a single letter being correct
    # is the fraction of keys which are that letter.
    C = keyboard.count(target[i])
    P = P * C / len(keyboard);
  return P

for tc in range(input()):
  K, L, S = map(int, raw_input().split(' '))
  keyboard = raw_input()
  target = raw_input()
  res = 0
  P = probability(target, keyboard)
  if P > 0:
    O = max_overlap(target)
    max_copies = 1.0 + (S-L) / (L-O)
    min_copies = P * (S-L+1)
    res = max_copies - min_copies
  print("Case #%d: %f" % (tc + 1, res))

