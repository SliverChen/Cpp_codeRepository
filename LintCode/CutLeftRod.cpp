class Solution {
public:
    /**
     * @param costPerCut: integer cost to make a cut 
     * @param salePrice: integer per unit length sales price 
     * @param lengths: an array of integer rod lengths 
     * @return: The function must return an integer that denotes the maximum possible profit. 
     */
    int maxProfit(int costPerCut, int salePrice, vector<int> &lengths) {
        int n = lengths.size();
        int minLength = lengths[0];
        int maxLength = lengths[0];
        int totalLength = lengths[0];
        int cutCount = 0;
        int TotalNum = 0;
        int avgLength;
        for(int i = 1;i<n;i++)
        {
          if(minLength > lengths[i])  //get min Length
          {
            minLength = lengths[i];
          }
          if(maxLength < lengths[i])  //get max Length
          {
            maxLength = lengths[i];
          }
          totalLength += lengths[i];  //calculate total lengths
        }

        int minLeft = maxLength;

        for(int i=minLength;i<=maxLength;i++)
        {
            int Count;
            Count = totalLength / i;
            int curLeft = totalLength - Count * i;
            if(minLeft > curLeft)
            {
              minLeft = curLeft;
              avgLength = i;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(lengths[i] % avgLength == 0)
            {
              TotalNum += lengths[i] / avgLength;
              cutCount += lengths[i] / avgLength - 1;
              continue;
            }
            TotalNum += lengths[i] / avgLength;
            cutCount += lengths[i] / avgLength;
        }

        int result = TotalNum * avgLength * salePrice - cutCount * costPerCut;
        return result;
    }
};