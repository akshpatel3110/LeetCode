class TrieNode(object):
    def __init__(self):
        self.dic = {}
        self.word = ''

class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        res = []
        root = self.buildTrie(words)
        m = len(board)
        n = len(board[0])
        
        cur_visited = [[False] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                self.dfs(board, i, j, root, res, cur_visited, m, n)
        return res
    
    def dfs(self, board, i, j, node, res, cur_visited, m, n):
        if i < 0 or i >= m or j < 0 or j >= n or cur_visited[i][j]:
            return
        
        if board[i][j] not in node.dic:
            return
        
        node = node.dic[board[i][j]]
                
        # ['a', 'a']
        # ['a']
        if node.word:
            res.append(node.word)
            node.word = ''
            
        cur_visited[i][j] = True
        for row, col in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
            self.dfs(board, row, col, node, res, cur_visited, m, n)
        cur_visited[i][j] = False

        
        
    def buildTrie(self, words):
        root = TrieNode()
        for word in words:
            p = root
            for c in word:
                if c not in p.dic:
                    p.dic[c] = TrieNode()
                p = p.dic[c]
            p.word = word
        return root
