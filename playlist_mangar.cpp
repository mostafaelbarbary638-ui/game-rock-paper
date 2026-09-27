#include <bits/stdc++.h>

using namespace std ;

class mediaitem
{
protected :
    virtual void play() = 0 ;
    virtual void getinfo() = 0 ;
};
class library
{

public :
    // attributes ;
    vector <string> title , artist , genre , duration , type  , epnumber ;
    vector <int> plays ;
    string t, a , g , d , epnums ;
    int choose1 ; bool flag1 = true ;
    string delete_item ;
    // methods ;
    void all_library()
    {
        cout <<"------------ LIBRARY -------------------\n"
                "1. Add song\n"
                "2. Add podcast\n"
                "3. View all\n"
                "4. Delete item\n"
                "0. Back\n"
            "-----------------------------------------\n" ;
        while(flag1)
        {
            cout << "Choose1 : " ; cin >> choose1;
            // add song ;
            if(choose1 == 1)
            {
                cin.ignore() ;
                plays.push_back(0) ;
                type.push_back("song") ;
                epnumber.push_back("none") ;
                cout << "\nTITLE : " ; getline(cin, t) ; title.push_back(t);
                cout << "ARTIST  : " ; getline(cin, a) ; artist.push_back(a) ;
                cout << "DURATION : " ; getline(cin, d ) ; duration.push_back(d) ;
                cout << "GENRE   :" ; getline(cin, g) ; genre.push_back(g) ;
                cout << "\n[OK] Added." << "Library has " << title.size() << " item\n\n" ;
            }
            // add podcast ;
            else if(choose1 == 2)
            {
                cin.ignore() ;
                plays.push_back(0) ;
                type.push_back("podcast") ;
                genre.push_back("none") ;
                cout << "\nTITLE  : " ; getline(cin, t) ; title.push_back(t);
                cout << "HOST    : " ; getline(cin, a) ; artist.push_back(a) ;
                cout << "DURATION : " ; getline(cin, d ) ; duration.push_back(d) ;
                cout << "epsoide number :" ; getline(cin, epnums) ; epnumber.push_back(epnums) ;
                cout << "\n[OK] Added." << "Library has " << title.size() << " item\n\n" ;
            }
            // view all thing in library ;
            else if(choose1 == 3)
            {
                cout << "\nID "<< "TYPE "<< "TITLE "<< "BY "<< "LENGTH "<< "PLAYS" << endl  ;
                for(int i = 0 ; i < title.size(); i++)
                {
                    if(type[i] == "song")
                    {
                        cout<< "0"<< i+1 << " - " <<  type[i] << " - " << title[i] << " - " << artist[i] << " - " << duration[i] << " - " << plays[i] <<endl ;
                    }
                    else
                    {
                        cout << "0"<<i+1 << " - " << type[i] << " - " << "EP."<< epnumber[i] << " - " << title[i] << " - " << artist[i] << " - " << duration[i] << " - " << plays[i] << endl ;
                    }
                }
            }
             // delete item in library ;
            else if(choose1 == 4)
            {
                cin.ignore();
                cout << "\ntitle :" ; getline(cin, delete_item)  ;
                for(int i = 0 ; i < title.size() ; i++)
                {
                    if(delete_item == title[i])
                    {
                        title.erase(title.begin() + i) ;
                        artist.erase(artist.begin() + i) ;
                        genre.erase(genre.begin() + i) ;
                        duration.erase(duration.begin() + i) ;
                        type.erase(type.begin() + i) ;
                        epnumber.erase(epnumber.begin() + i ) ;
                        cout << "\n[OK] deleted. " << "the library has " << title.size() << " items" << endl ;
                        break ;
                    }
                    else
                    {
                        if(i == (title.size()-1) && delete_item != title[i])
                        {
                            cout << "\nthis " << type[i] << " is not here in library!"<< endl ;
                        }
                    }
                }
            }
            else
            {
                system("cls") ;
                flag1 = false ;
            }
          }
    }
};

class playlist : public library , protected mediaitem
{
protected :
    // atrributes ;
    vector <string> name, person,time , s_p , epsoide_nums  ;
    //float total = 0 ;
    string add_item , dele_item ;
    int choose2 ; bool flag2 = true ;
    int engine = 0 ;
    string answer ;
    int counter ;
    // outputs ;
public :
    void getinfo()
            {
                if (s_p[engine] == "song")
                {
                    plays[engine] += 1 ;
                cout << "\n>>> NOW PLAYIING: " << name[engine] << " - " << person[engine] << " (" << time[engine] << ")" << endl ;
                      cout <<"["<< s_p[engine] << "] " << "streaming audio...                   "<< "[" << s_p[engine] << "::play]" << endl  ;
                }
                else
                {
                    plays[engine] += 1 ;
                cout << "\n>>> NOW PLAYIING: " << "Ep." << epsoide_nums[engine] << name[engine] << " (" << time[engine] << ")" << endl ;
                      cout <<"["<< s_p[engine] << "] " << "episode " << epsoide_nums[engine] << ", hosted by " << person[engine] << "      [" << s_p[engine] << "::play]" <<  endl  ;
                }
            }
    void play()
            {
                bool condition = true ;
                while(condition)
                {
                    cout << "\n\n (n) next   (p) previous   (q) quit" << endl ;
                    cout << "> " ; cin >> answer ;
                    if (answer == "n")
                    {
                        if(engine+1 > (name.size()-1)) {cout << "[!] You are on the last track." << endl << endl ; }
                        else { engine+= 1 ; getinfo() ; }
                    }
                    else if (answer == "p")
                    {
                        if(engine-1 < 0) { cout << "[!] this is the first track." << endl << endl ; }
                        else { engine -= 1 ; getinfo() ;}
                    }
                    else
                    {
                        condition = false ;
                    }
                }
            }
    void output()
    {
         cout <<"---------------playlist---------------\n"
                " 1.Add \n"
                " 2.Remove\n"
                " 3.Play It\n"
                " 4.Total Duration\n"
                " 5.Playlist Forwards\n"
                " 6.Playlist Backwards\n"
                " 0. Back\n"
               "---------------------------------------\n" ;
    while(flag2)
    {
        cout << "\nchoose2 :" ; cin >> choose2 ;
        if(choose2 == 1)
        {
            cin.ignore() ;
            cout << "\ntitle : " ; getline(cin, add_item) ;
            for(int i = 0; i < title.size() ; i++)
            {
                if(add_item == title[i])
                {
                    name.push_back(title[i]) ;
                    person.push_back(artist[i]) ;
                    time.push_back(duration[i]) ;
                    s_p.push_back(type[i]) ;
                    if(type[i] == "song") {epsoide_nums.push_back("none") ; }
                    else {epsoide_nums.push_back(epnumber[i]) ; }
                    cout << "\n[OK] added. the playlist has " << name.size() << " items."<< endl;
                    break ;
                }
                else
                {
                    if(i == (title.size()-1) && add_item != title[i])
                    {
                        cout << "\n this " << "("<< add_item <<")" << " is not in library!" << endl ;
                    }
                }
            }
        }
        else if (choose2 == 2)
        {
            cin.ignore() ;
            cout << "\nTitle : " ; getline(cin, dele_item) ;
            for(int a = 0 ; a < name.size() ; a++)
            {
                if(dele_item == name[a])
                {
                    name.erase(name.begin() + a) ;
                    person.erase(person.begin() + a) ;
                    time.erase(time.begin() + a) ;
                    s_p.erase(s_p.begin() + a) ;
                    cout << "\n[OK] deleted. the playlist has " << name.size() << " items" << endl ;
                    break ;
                }
                else
                {
                    if(a == (name.size()-1) && dele_item != name[a])
                    {
                        cout << "\n this " << dele_item << " is not in the playlist" << endl ;
                    }
                }
            }
        }
        else if (choose2 == 3)
        {
            getinfo() ;
            play() ;
        }
        else if (choose2 == 5)
        {
           for(int x = 0 ; x< name.size() ; x++)
           {
               cout << x+1 << ". " << name[x] << endl ;
           }
        }
        else if (choose2 == 6)
        {
            int counter = name.size() ;
            for(int x = name.size()-1 ; x >= 0 ; x--)
           {
               cout << x+1 << ". " << name[x] << endl ;
           }
        }
        else { system("cls") ; flag2 = false ; }
    }
    }

};

class node
{
public :
    string data ;
    node *next ;

};
class up_next : public playlist
{
private :
    int choose3 ; bool flag3 = true ;
    // songer name ;
    vector <string> name1 , epn ;
    int counter = 1 ;
    int counter2 = 0 ;
    int track_id ;
    node *head ;
    node *tail ;
public :
    up_next() {head = tail = nullptr ; }
    bool isempty()
    {
        if(head == nullptr && tail == nullptr)
            return true ;
        else
            return false ;
    }
    void Enqueue(string item)
    {
        node *new_node =  new node() ;
        new_node->data = item ;
        new_node->next = nullptr ;
        if(isempty())
        {
            head = tail = new_node ;
        }
        else
        {
            tail->next = new_node ;
            tail = new_node ;
        }
    }
    void display()
    {
        // check before run if queue has any item orr not ;
        if(isempty())
        {
            cout << "the queue is empty!" << endl ;
        }
        else
        {
            node *temp = head ;
            while(temp != nullptr)
                {
                    cout << counter << ". " << temp->data << endl ;
                    temp = temp->next ;
                    counter += 1;
                 }

        }
    }
     int count_queue()
    {
        int counter= 0 ;
        node *temp = head ;
        while(temp != nullptr)
        {
            counter += 1 ;
            temp = temp->next ;
        }
        return counter ;
    }
    void run_queue()
    {
        cout << "----------- UP NEXT ---------------------\n"
                 "1. Add to queue\n"
                 "2. View queue\n"
                 "3. Play next from queue\n"
                 "0. Back\n"
               "-----------------------------------------\n" ;
        while(flag3)
        {
            cout << "\nchoose3 : " ; cin >> choose3 ;
            if (choose3 == 1)
            {
                cout << "\ntrack ID : " ; cin >> track_id ;
                track_id-=1 ;
                if (track_id < 0 || track_id >= title.size())
                {
                    cout << "\n [!] invalid track id!" << endl ;
                }
                else
                {
                string result = title[track_id] ;
                Enqueue(result) ;
                cout << "\n[OK] " << result << " added to the queue." << endl ;
                name1.push_back(artist[track_id]) ;
                epn.push_back(epnumber[track_id]) ;
                }
            }
            else if (choose3 == 2)
            {
                display() ;
            }
            else if (choose3 == 3)
            {
                node *temp = head ;
                if(isempty()) {cout << "queue is empty!" ;}
                else
                {
                    cout << "\n>>> NOW PLAYING: " << head->data << " - " << name1[counter2] << endl ;
                    counter2 += 1 ;
                    head = head->next ;
                    if (head == nullptr) {tail = nullptr ;}
                    cout  << "\n " << count_queue()  << " track left in the queue." << endl ;
                    delete temp ;
                }

            }
            else
            {
                system("cls") ;
                flag3 = false ;
            }
        }
    }
};

class search_sort : public up_next
{
private :
  // attributes ;
  int choose4 ; bool flag4 = true ;
  string title_binary ;
  char answer ;
  string title_linear ;
  int sorted_by ;
  // linear search ;
public :
  vector<int> linear_search1(string target1, int field)
  {
      vector <int> nums ;
      for(int i =0; i < title.size(); i++)
      {
          string which_one = (field==1) ? artist[i] : genre[i] ;
          if(which_one == target1)
            nums.push_back(i) ;
      }
      return nums ;
  }
  // binary search ;

  int binary_search2(string target)
  {
      int left = 0 ;
      int right = title.size()-1 ;

      while(left <= right)
      {
          int mid = (left+right) / 2 ;
          if(title[mid] == target)
            return mid ;
          else if (title[mid] < target)
            left = mid + 1 ;
          else
            right = mid - 1 ;

      }
      return -1 ;
  }
  int selection_sort(int value)
  {
      // comparison -> ;
      int nums = 0 ;
      for(int i = 0; i < title.size()-1 ; i++)
      {
          int minindex = i ;
          for(int j = i+1 ; j < title.size() ; j++)
          {
              nums+= 1;
              bool condition ;
              if(value == 1)
              {
                  condition = (title[j] < title[minindex] ) ;
              }
              else
              {
                  condition = (plays[j] < plays[minindex] ) ;
              }
              if(condition)
                minindex = j ;

              swap(title[minindex], title[i]) ;
              swap(artist[minindex], artist[i]) ;
              swap(duration[minindex], duration[i]) ;
              swap(genre[minindex], genre[i]) ;
              swap(type[minindex], type[i]) ;
              swap(epnumber[minindex], epnumber[i]) ;
              swap(plays[minindex], plays[i]) ;

         }
      }
      return nums ;
    }
  void output_search()
  {
      cout << "--------------search and sort------------\n"
               "1. Search by exact title\n"
               "2. Filter by artist or genre\n"
               "3. Sort library\n"
               "0. back\n" ;
    while(flag4)
    {
        cout << "\nchoose4 : " ; cin >> choose4 ;
        if(choose4 == 1)
        {
            cin.ignore() ;
            cout << "\ntitle :" ; getline(cin, title_linear) ;
            int result = binary_search2(title_linear) ;
            if (result == -1)
            {
                cout << "\ndoes not exist!" << endl ;
            }
            else
            {
                cout << "\nfound.\n" << endl ;
                cout << result-1 << " " << type[result] << " " << title[result] << " " << artist[result] << " " << duration[result] << " " << "plays: " << plays[result] << endl ;
            }
        }
        else if (choose4 == 2)
        {
            cout << "\nartist or genre [a/g] :" ; cin >> answer ;
            int field = (answer == 'a' || answer == 'A') ? 1 : 2 ;
            cin.ignore() ;
            cout << "\n" << (field == 1 ? "Artist" : "Genre" ) << " : " ; getline(cin, title_linear) ;
            vector <int> result2 =  linear_search1(title_linear, field) ;
            if (result2.size() == 0)
                {
                    cout << "\nNOT FOUND!" << endl ;
                }
            else
            {
                cout << "\n" << result2.size() << "matches\n" << endl ;
                for(int i = 0 ; i < result2.size() ; i++)
                {
                    int check =result2[i] ;
                    cout << "0" << i+1 << ". " << title[check] << " - " << artist[check] << endl ;
                }
            }
        }
         else if (choose4 == 3)
         {
             cout << "\nSort by (1) title (2) duration (3) play count : " ; cin >> sorted_by ;
             if(sorted_by == 1)
             {
                 int nums = selection_sort(sorted_by) ;
                 cout << "\nID  " << "TITLE " << endl ;
                 for(int i = 0 ; i < title.size() ; i++)
                 {
                     cout << "0"<< i+1 << "  " << title[i] << endl ;
                 }
                 cout << "\nSorted in "<< nums << " comparisons." << endl ;
             }
             else if(sorted_by == 2)
             {
                 cout << "\nnot avalible yet!" << endl ;
             }
             else if (sorted_by == 3)
             {
                 int nums = selection_sort(sorted_by) ;
                 cout << "\nID     TITLe     PLAYS" << endl ;
                 for(int i = 0; i < title.size(); i++)
                 {
                     cout << "0"<< i+1 << "  " << title[i] << "     "<< plays[i] << endl ;
                 }
                 cout << "\nSorted in "<< nums << " comparisons." << endl ;
             }
             else {cout << "\ninvalid number! " ; }

         }
         else
         {
             system("cls") ;
             flag4 = false ;
         }
    }
  }
  // methods

};

class stats : public search_sort
{
public :
    void top_plays()
    {
        cout << "\n TOP 5 MOST PLAYED\n" << endl ;
        if (plays.size() == 0)
        {
            cout <<"\nlibrary is empty!" << endl ;
        }
        else
        {
            for(int a = 0 ; a < plays.size()-1 ; a++)
                {
                    for(int i = 0 ; i< plays.size()-1 ; i++)
                    {
                        if(plays[i] > plays[i+1])
                        {
                            swap(plays[i], plays[i+1]) ;
                            swap(genre[i], genre[i+1]) ;
                            swap(title[i], title[i+1]) ;
                            swap(duration[i], duration[i+1]) ;
                            swap(epnumber[i], epnumber[i+1]) ;
                            swap(artist[i],artist[i+1]) ;
                            swap(type[i], type[i+1]) ;
                        }
                    }
                }
                int counter = 1 ;
                for(int x = title.size()-1 ; x >= 0;x--)
                    {
                        cout << counter << "." << title[x] << " "<< plays[x] << " plays" << endl ;
                        counter += 1 ;
                    }
                cout << "\nlibrary total : " << title.size() << " items" << endl ;
            }
        }
};
int main()
{
    // object class ;
    //playlist p1 ;
    //up_next un ;
    //search_sort ss ;
    stats ss ;
    // varibles ;
    int choose ; bool flag = true ;
    while(flag)
        {
            // outputs ;
    cout << "=========================================\n"
            "           PLAYLIST MANAGER\n"
             "=========================================\n"
              "1. Library\n"
              "2. Playlist\n"
              "3. Up Next queue\n"
              "4. Search and sort\n"
              "5. Stats\n"
              "0. Exit\n"
            "-----------------------------------------\n" ;
            cout << "Choose : " ; cin >> choose ;
            if(choose == 1)
                {
                    system("cls") ;
                    ss.all_library() ;
                }
            else if (choose == 2)
            {
                system("cls") ;
                ss.output() ;

            }
            else if (choose == 3)
            {
                system("cls") ;
                ss.run_queue() ;
            }
            else if (choose == 4)
            {
                system("cls") ;
                ss.output_search() ;
            }
            else if (choose == 5)
            {
                system("cls") ;
                ss.top_plays() ;
                system("pause") ; system("cls") ;
            }
            else
                {
                    flag = false ;
                }

    }
    return 0 ;
}
