#include <bits/stdc++.h>
using namespace std;
int main() {
string str;        // declaration type 1                
string str2 ("this is handsome",2,7);  // declaration type 2
string str5 (10,'x');   //declaring the string initializing with repeatitive character

cin>>str;            //it takes input until a space comes
getline(cin,str);                  //getline() takes input until a line break comes

cout<<"the string is : ";
for(auto it=str2.begin(); it != str2.end(); it++){   // demonstrating the use of begin() and end() function
    cout<< *it; 
}

string str3 = "this is string 3";  
cout<<endl<<str3<<endl;      // printing the string directly
cout<<"the length of the str2 is : "<<str2.size()<<" "<<str2.length()<<endl;
cout<<"the maximum length that the string can reach is : "<< str2.max_size()<<endl;

string str4("the cool language c");
cout<<str4<<endl;
str4.resize(str4.size()+2, '+');
cout<<str4<<endl;
str4.resize(str4.size()-4);
cout<<str4<<endl;

cout<<str4.back()<<endl;
cout<<str4.front()<<endl;

string str6("");
string str7="Writing ";
string str8="print 10 and then 5 more";

  // used in the same order as described above:
  str6.append(str7);                       // "Writing "
  str6.append(str8,6,3);                   // "10 "
  str6.append("dots are cool",5);          // "dots "
  str6.append("here: ");                   // "here: "
  str6.append(10,'.');                    // ".........."
  str6.append(str8.begin()+8,str8.end());  // " and then 5 more"
cout<<str6<<endl;

string str9;
string base="The quick brown fox jumps over a lazy dog.";

  // used in the same order as described above:

  str9.assign(base);
  cout << str9 << '\n';

  str9.assign(base,10,9);
  cout << str9 << '\n';         // "brown fox"

  str9.assign("pangrams are cool",7);
  cout << str9 << '\n';         // "pangram"

  str9.assign("c-string");
  cout << str9 << '\n';         // "c-string"

  str9.assign(10,'*');
  cout << str9 << '\n';         // "**********"

  str9.assign(base.begin()+16,base.end()-12);
  cout << str9 << '\n';         // "fox jumps over"

string str10="to be question";
  string str11="the ";
  string str12="or not to be";
  string::iterator it1;

  // used in the same order as described above:
  str10.insert(6,str11);                 // to be (the )question
  str10.insert(6,str12,3,4);             // to be (not )the question
  str10.insert(10,"that is cool",8);    // to be not (that is )the question
  str10.insert(10,"to be ");            // to be not (to be )that is the question
  str10.insert(15,1,':');               // to be not to be(:) that is the question
  it1 = str10.insert(str10.begin()+5,','); // to be(,) not to be: that is the question
  str10.insert (str10.end(),3,'.');       // to be, not to be: that is the question(...)
  str10.insert (it1 + 2,str12.begin(),str12.begin()+3); // (or )

  cout << str10 << '\n';

string str13 ("This is an example sentence.");
  cout << str13 << '\n';
                                           // "This is an example sentence."
  str13.erase (10,8);                        //            ^^^^^^^^
  cout << str13 << '\n';
                                           // "This is an sentence."
  str13.erase (str13.begin()+9);               //           ^
  cout << str13 << '\n';
                                           // "This is a sentence."
  str13.erase (str13.begin()+5, str13.end()-9);  //       ^^^^^
  cout << str13 << '\n';
                                           // "This sentence."
                    
string base2 ="this is a test string.";
  string str14="n example";
  string str15="sample phrase";
  string str16="useful.";

  // replace signatures used in the same order as described above:

  // Using positions:                 0123456789*123456789*12345
  string str17 = base2;              // "this is a test string."
  str17.replace(9,5,str14);         // "this is an example string." (1)
  str17.replace(19,6,str15,7,6);    // "this is an example phrase." (2)
  str17.replace(8,10,"just a");     // "this is just a phrase."     (3)
  str17.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
  str17.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)

  // Using iterators:                                                        0123456789*123456789*
  str17.replace(str17.begin(),str17.end()-3,str15);                      // "sample phrase!!!"      (1)
  str17.replace(str17.begin(),str17.begin()+6,"replace");                // "replace phrase!!!"     (3)
  str17.replace(str17.begin()+8,str17.begin()+14,"is coolness",7);       // "replace is cool!!!"    (4)
  str17.replace(str17.begin()+12,str17.end()-4,4,'o');                   // "replace is cooool!!!"  (5)
  str17.replace(str17.begin()+11,str17.end(),str16.begin(),str16.end()); // "replace is useful."    (6)
  cout << str17 << '\n';

string buyer ("money");
  string seller ("goods");

  cout << "Before the swap, buyer has " << buyer;
  cout << " and seller has " << seller << '\n';

  seller.swap (buyer);

  cout << " After the swap, buyer has " << buyer;
  cout << " and seller has " << seller << '\n';

string str18="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)
  string str19 = str18.substr (3,5);     // "think"
  int pos = str18.find("live");      // position of "live" in str
  string str20 = str18.substr (pos);     // get from "live" to the end

  cout << str19 << ' ' << str20 << '\n';

string str21 ("green apple");
  string str22 ("red apple");

  if (str21.compare(str22) != 0)
    cout << str21 << " is not " << str22 << '\n';

  if (str21.compare(6,5,"apple") == 0)
    cout << "still, " << str21 << " is an apple\n";

  if (str22.compare(str22.size()-5,5,"apple") == 0)
    cout << "and " << str22 << " is also an apple\n";

  if (str21.compare(6,5,str22,4,5) == 0)
    cout << "therefore, both are apples\n";

string str23 ("There are two needles in this haystack with needles.");
  string str24 ("needle");

  // different member versions of find in the same order as above:
  int found = str23.find(str24);    //find the first occurence of str24 in str23
  if (found!= str23.max_size())     // checking if it has crossed the max size of the string
    cout << "first 'needle' found at: " << found << '\n';   //if not found , then it returns -1

  found=str23.find("needles are small",found+1,6);
  if (found!= str23.max_size())
    cout << "second 'needle' found at: " << found << '\n';

  found=str23.find("haystack");
  if (found!= str23.max_size())
    cout << "'haystack' also found at: " << found << '\n';

  found=str23.find('.');
  if (found!= str23.max_size())
    cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str23.replace(str23.find(str24),str24.length(),"preposition");
  cout << str23 << '\n';

string str25 ("The sixth sick sheik's sixth sheep's sick.");
  string key ("sixth");

  found = str25.rfind(key);
  if (found!= str25.max_size())
    str25.replace (found,key.length(),"seventh");

  cout << str25 << '\n';

 string str26 ("Please, replace the vowels in this sentence by asterisks.");
  found = str26.find_first_of("aeiou");
  int size = str26.size();
  while (size--)
  {
    str26[found]='*';
    found=str26.find_first_of("aeiou",found+1);
  }

  cout << str26 << '\n';

string str27 ("/usr/bin/man");
cout << "Splitting: " << str27 << '\n';
  found = str27.find_last_of("/\\");
  cout << " path: " << str27.substr(0,found) << '\n';
  cout << " file: " << str27.substr(found+1) << '\n';

string str28 ("look for non-alphabetic characters...");
  found = str28.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

  if (found!= str28.max_size())
  {
    cout << "The first non-alphabetic character is " << str28[found];
    cout << " at position " << found << '\n';
  }

string foo = "foo";
  string bar = "bar";

  if (foo==bar) cout << "foo and bar are equal\n";
  if (foo!=bar) cout << "foo and bar are not equal\n";
  if (foo< bar) cout << "foo is less than bar\n";
  if (foo> bar) cout << "foo is greater than bar\n";
  if (foo<=bar) cout << "foo is less than or equal to bar\n";
  if (foo>=bar) cout << "foo is greater than or equal to bar\n";

string str29 ("Please split this sentence into tokens");

  char * cstr = new char [str29.length()+1];
  strcpy (cstr, str29.c_str());
  cout<<cstr;


string str90 = "geesks";
str90.replace(3,1,"");
cout<<endl<<str90;
return 0;
}