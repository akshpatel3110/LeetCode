class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> m;

        m["Jan"] = "01";
        m["Feb"] = "02";
        m["Mar"] = "03";
        m["Apr"] = "04";
        m["May"] = "05";
        m["Jun"] = "06";
        m["Jul"] = "07";
        m["Aug"] = "08";
        m["Sep"] = "09";
        m["Oct"] = "10";
        m["Nov"] = "11";
        m["Dec"] = "12";
        
        string day;
        int offset;

        if (!isdigit(date[1])) {
            day = "0" + date.substr(0, 1);
            offset = 0;
        } else {
            day = date.substr(0, 2);
            offset = 1;
        }
        string month(m[date.substr(4 + offset, 3)]);
        string year(date.substr(8 + offset));
        return year + "-" + month + "-" + day;      
    }
};
