class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;

        for (int x : nums1) {
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        // We can make everything even
        // if there is at least one number of the
        // required parity to subtract.
        if (even > 0)
            return true;

        // If all numbers are odd, subtracting
        // one odd number from every other odd number
        // makes them even.
        if (odd > 0)
            return true;

        return false;
    }
};