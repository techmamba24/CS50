import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positives = set()
        self.negatives = set()
        self.tokenizer = nltk.tokenize.TweetTokenizer()
        
        with open(positives, "r") as f:
            for line in f:
                if not line.startswith(';'):
                    self.positives.add(line.strip())
        
        with open(negatives, "r") as f:
            for line in f:
                if not line.startswith(';'):
                    self.negatives.add(line.strip())
        
    def analyze(self, text):
        score = 0
        tokens = self.tokenizer.tokenize(text)
        for token in tokens:
            if token.lower() in self.positives:
                score+=1
            elif token.lower() in self.negatives:
                score-=1
        return score
