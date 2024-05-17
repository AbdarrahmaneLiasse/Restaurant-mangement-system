#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
struct Ingredient{
    string nom;
    int Qte;
    void afficher(){
        cout<<"Nom:"<<nom<<"-------------"<<"Qte:"<<Qte<<endl;
    }
    string getnom(){
        return nom;
    }
    int getQte(){
        return Qte;
    }
    friend bool operator ==(Ingredient& i,Ingredient& i2){
        if(i2.nom==i.nom && i2.Qte==i.Qte)return true;
        else return false;
    }
   
};






//class Plat
class Plat{
    string nom,Desc;
    float prix;
    vector<Ingredient> ListIngredients;

    public:
    Plat(string n,string d,float p,vector<Ingredient> &LIng):nom(n),Desc(d),prix(p),ListIngredients(LIng){}
    void Afficher(){
        cout<<"Nom:"<<nom<<endl;
        cout<<"Desc:"<<Desc<<endl;
        cout<<"prix:"<<prix<<endl;
        cout<<"Liste des ingredients:"<<endl;
        cout<<"----------"<<endl;
        for(int i=0;i<ListIngredients.size();i++){
            ListIngredients[i].afficher();
        }
    }
    string getnom(){
        return nom;
    }
    float getPrix(){
        return prix;
    }
    vector<Ingredient> LI(){
        return ListIngredients;
    }
    void setnom(string &no){
        nom=no;
    }
    void setDesc(string &d){
        Desc=d;
    }
    void setPrix(float &p){
        prix=p;
    }
    void setIngredient(string &nI){
        for(int i=0;i<ListIngredients.size();i++){
            if(nI==ListIngredients[i].nom){
                cout<<"Modifier la quantite necessaire"<<endl;
                cin>>ListIngredients[i].Qte;
            }
        }    
    }
};








//class Boisson
class Boisson{
    string nom,Desc;
    float prix;
    vector<Ingredient> ListIngredients;
    public:
    Boisson(string n,string d,float p,vector<Ingredient> &LIng):nom(n),Desc(d),prix(p),ListIngredients(LIng){}
    float getPrix(){
        return prix;
    }
    string getnom(){
        return nom;
    }
    vector<Ingredient> LI(){
        return ListIngredients;
    }
    void Afficher(){
        cout<<"Nom:"<<nom<<endl;
        cout<<"Desc:"<<Desc<<endl;
        cout<<"prix:"<<prix<<endl;
        cout<<"Liste des ingredients:"<<endl;
        cout<<"----------"<<endl;
        for(int i=0;i<ListIngredients.size();i++){
            ListIngredients[i].afficher();
        }
    }
    void setnom(string &no){
        nom=no;
    }
    void setDesc(string &d){
        Desc=d;
    }
    void setPrix(float &p){
        prix=p;
    }
    void setIngredient(string &nI){
        for(int i=0;i<ListIngredients.size();i++){
            if(nI==ListIngredients[i].nom){
                cout<<"Modifier la quantite necessaire"<<endl;
                cin>>ListIngredients[i].Qte;
            }
        }    
    }
};







//class Commande
class Commande{
        vector<Plat> ListPlatsCommander;
        vector<Boisson> ListBoissonsCommander;
        public:
        Commande(){
            ListPlatsCommander=vector<Plat>();
            ListBoissonsCommander=vector<Boisson>();}
        Commande(vector<Plat> &LPC,vector<Boisson> &LBC):ListPlatsCommander(LPC),ListBoissonsCommander(LBC){}
        void AjouterPlat(Plat &p){
            ListPlatsCommander.push_back(p);
        }
        void AjouterBoisson(Boisson &b){
            ListBoissonsCommander.push_back(b);
        }
        float CalculerTotal(){
            float somme=0;
            for(int i=0;i<ListPlatsCommander.size();i++){
                somme+=ListPlatsCommander[i].getPrix();
            }
            for(int j=0;j<ListBoissonsCommander.size();j++){
                somme+=ListBoissonsCommander[j].getPrix();
            }
            return somme;
        }
        void AfficherDetail(){
            cout<<"Commande: "<<endl;
            for(int i=0;i<ListPlatsCommander.size();i++){
                cout<<ListPlatsCommander[i].getnom()<<"----------------"<<ListPlatsCommander[i].getPrix()<<endl;
            }
            for(int j=0;j<ListBoissonsCommander.size();j++){
                cout<<ListBoissonsCommander[j].getnom()<<"----------------"<<ListBoissonsCommander[j].getPrix()<<endl;

            }
        }
};














//class stock
class Stock{
    vector<Ingredient> ListIngredients;
    public:
    Stock(vector<Ingredient> &LIng):ListIngredients(LIng){}
    void AjouterIngredient(Ingredient &I){
        ListIngredients.push_back(I);
    }
    void seIngredients(vector<Ingredient> &LI){
        ListIngredients=LI;
    }
   
    void MAJ(Ingredient &In){
        for(int i=0;i<ListIngredients.size();i++){
            {
                ListIngredients[i].Qte-=In.Qte;
            }
            
        }
    }
    void AfficherDetail(){
        cout<<"Liste des ingredients"<<endl;
        for(int i=0;i<ListIngredients.size();i++){
            ListIngredients[i].afficher();
        }
    }
};










//class Reservation
class Reservation{
    string date,heure;
    int nbrPersonne;
    public:
    Reservation(){date="";heure="";nbrPersonne=0;}
    Reservation(string d,string h,int np):date(d),heure(h),nbrPersonne(np){}

    
    void AfficherDetail(){
        cout<<"Date:       "<<date<<endl;
        cout<<"Heure:     "<<heure<<endl;
        cout<<"Nombre de personne:  "<<nbrPersonne<<endl;
    }
    string getDate(){return date;}
    void setDate(string &d){
        date=d;
    }
    void setHeure(string &h){
        heure=h;
    }
    void setNbrP(int &nP){
        nbrPersonne=nP;
    }
};













//class client
class Client{
    string nom;
    string numTel;
    vector<Reservation> ListReservations;
    public:
    Client(){nom="";numTel="";ListReservations=vector<Reservation>();}
    Client(string n,string numT,vector<Reservation> &LR):nom(n),numTel(numT),ListReservations(LR){};
    void Reserver(Reservation &r){
        ListReservations.push_back(r);
    }
    string getnom(){
        return nom;
    }
    vector<Reservation> LR(){
        return ListReservations;
    }
    
    void setnom(string &nom){this->nom=nom;}
    void setNT(string &ntel){numTel=ntel;}
    void setLR(vector<Reservation> &lr){ListReservations=lr;}
    void AfficherDetail(){
        cout<<"Nom:       "<<nom<<endl;
        cout<<"numTel:     "<<numTel<<endl;
        cout<<"Liste de reservations"<<endl;
        for(int i=0;i<ListReservations.size();i++){
            cout<<"List de Reservation:  "<<endl;
            ListReservations[i].AfficherDetail();
        }
    }
};


//List de client
class ListClient{
    vector<Client> lc;
    public:
    ListClient(){
        lc=vector<Client>();
    }
    ListClient(vector<Client> &LC){lc=LC;}
    
    bool rechercher(string &n){
        for(int i=0;i<lc.size();i++){
            if(n==lc[i].getnom())
               return true;
            else return false;
        }
    }
    vector<Client> getLC(){
        return lc;
    }
    void ajouterClient(Client &c){
        lc.push_back(c);
    }
    void setClient(Client &c){
        for(int i=0;i<lc.size();i++){
            lc[i]=c;
        }
    }
};

















//class Menu
class Menu{
    vector<Plat> ListPlats;
    vector<Boisson> ListBoissons;
    
    public:
    Menu():ListPlats(vector<Plat>()),ListBoissons(vector<Boisson>()){}
    Menu(vector<Plat> &ListP,vector<Boisson> &ListB){
        ListPlats=ListP;
        ListBoissons=ListB;
    }
    vector<Plat> getListP(){
        return ListPlats;
    }
    vector<Boisson> getListB(){
        return ListBoissons;
    }
    void AjouterPlat(Plat &p){
        ListPlats.push_back(p);
    }
    void AjouterBoisson(Boisson &b){
        ListBoissons.push_back(b);
    }
    void SupprimerPlat(string &n){
        for(int i=0;i<ListPlats.size();i++){
            if(n==ListPlats[i].getnom()){
                ListPlats.erase(ListPlats.begin() + i);   
            }
        }
    }
    void SupprimerBoisson(string &n){
        for(int i=0;i<ListBoissons.size();i++){
            if(n==ListBoissons[i].getnom()){
                ListBoissons.erase(ListBoissons.begin() + i);   
            }
        }
    }
    
    void ModifierPlat(string &n){
        for(int i=0;i<ListPlats.size();i++){
            if(n==ListPlats[i].getnom()){
                cout<<"1-modifier le nom"<<endl;
                cout<<"2-modifier la description"<<endl;
                cout<<"3-modifier le prix"<<endl;
                cout<<"4-modifier un Ingredient"<<endl;
                char c;
                cin>>c;
                if(c=='1'){
                    cout<<"Saisir le nouveau nom: "<<endl;
                    string n;
                    cin>>n;
                    ListPlats[i].setnom(n);
                }
                else if(c=='2'){
                    cout<<"Saisir la nouvelle description: "<<endl;
                    string des;
                    cin>>des;
                    ListPlats[i].setDesc(des);
                }
                else if(c=='3'){
                    cout<<"Saisir le nouveau prix: "<<endl;
                    float pr;
                    cin>>pr;
                    ListPlats[i].setPrix(pr);
                }
                else if(c=='4'){
                    cout<<"Saisir la nouveau QTE: "<<endl;
                    string ni;
                    cin>>ni;
                    ListPlats[i].setIngredient(ni);
                }
            }
            else cout<<"Plat non trouver"<<endl;
   
        }
    }
    void ModifierBoisson(string &n){
        for(int i=0;i<ListBoissons.size();i++){
            if(n==ListBoissons[i].getnom()){
                cout<<"1-modifier le nom"<<endl;
                cout<<"2-modifier la description"<<endl;
                cout<<"3-modifier le prix"<<endl;
                cout<<"4-modifier un Ingredient"<<endl;
                char c;
                cin>>c;
                if(c=='1'){
                    cout<<"Saisir le nouveau nom: "<<endl;
                    string n;
                    cin>>n;
                    ListBoissons[i].setnom(n);
                }
                else if(c=='2'){
                    cout<<"Saisir la nouvelle description: "<<endl;
                    string des;
                    cin>>des;
                    ListBoissons[i].setDesc(des);
                }
                else if(c=='3'){
                    cout<<"Saisir le nouveau prix: "<<endl;
                    float pr;
                    cin>>pr;
                    ListBoissons[i].setPrix(pr);
                }
                else if(c=='4'){
                    cout<<"Saisir la nouveau QTE: "<<endl;
                    string ni;
                    cin>>ni;
                    ListBoissons[i].setIngredient(ni);
                }
            }
            else cout<<"Boisson non trouver"<<endl;
   
        }
    }
    void AfficherMenu(){
              for(int i=0;i<ListPlats.size();i++)
        {
            cout<<"Plat "<<i+1<<"- "<<endl;
           ListPlats[i].Afficher();
           cout<<"--------------------------"<<endl;
        }
        for(int i=0;i<ListBoissons.size();i++)
        {
             cout<<"Boisson "<<i+1<<" "<<endl;
            ListBoissons[i].Afficher();
            cout<<"--------------------------"<<endl;

        }
    }
    
};

















/*-----------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------*/









//GestiondeMenu
void GestiondeMenu(Menu &m,Stock &s){
    char choice;
    cout<<"Menu"<<endl;
    m.AfficherMenu();
    cout<<"1-Ajouter un plat"<<endl;
    cout<<"2-Ajouter un Boisson"<<endl;
    cout<<"3-Modifier un plat"<<endl;
    cout<<"4-Modifier un boisson"<<endl;
    cout<<"5-Supprimer un plat"<<endl;
    cout<<"6-Supprimer un boisson"<<endl;
    cout<<"Saisir votre choix"<<endl;
    cin>>choice;
    string no,des;
    float pr;
    vector<Ingredient> VI;
    Ingredient I;
    string nomT,nomPlat;
    int QTE;
    if(choice=='1'){
        cout<<"Ajouter un plat"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Saisir un nom"<<endl;
        cin>>no;
        cout<<"Saisir une description"<<endl;
        cin>>des;
        cout<<"Saisir un prix"<<endl;
        cin>>pr;
        
        bool w=true;
        while(w){
        cout<<"Ajouter des Ingredient"<<endl;
        cout<<"Nom ";cin>>nomT;cout<<endl;
        cout<<"Qte ";cin>>QTE;cout<<endl;
        I.nom=nomT;
        I.Qte=QTE;
        VI.push_back(I);
        
        char c;
        cout<<"a:Ajouter des Ingredients "<<"r:retour"<<endl;
        cin>>c;
            if(c=='r'){
                w=false;
            }
        }
        Plat pl(no,des,pr,VI);
        m.AjouterPlat(pl);
    }
    
    if(choice=='2'){
        
        cout<<"Ajouter un Boisson"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Saisir un nom"<<endl;
        cin>>no;
        cout<<"Saisir une description"<<endl;
        cin>>des;
        cout<<"Saisir un prix"<<endl;
        cin>>pr;
        bool w=true;
        while(w){
        
        cout<<"Ajouter des Ingredient"<<endl;
        cout<<"Nom ";cin>>nomT;cout<<endl;
        cout<<"Qte ";cin>>QTE;cout<<endl;
        I.nom=nomT;
        I.Qte=QTE;
        VI.push_back(I);
        Boisson boi(no,des,pr,VI);
        m.AjouterBoisson(boi);
        char c;
        cout<<"a:Ajouter des Ingredients "<<"r:retour"<<endl;
        cin>>c;
            if(c=='r'){
                w=false;
            }
        }
        
    }
    if(choice=='3'){
        m.AfficherMenu();
        cout<<"Saisir un plat"<<endl;
        cin>> nomPlat;
        m.ModifierPlat(nomPlat);
        
    }
    if(choice=='4'){
        m.AfficherMenu();
        cout<<"Saisir un Boisson"<<endl;
        cin>> nomPlat;
        m.ModifierBoisson(nomPlat);
    }
    if(choice=='5'){
        m.AfficherMenu();
        cout<<"Saisir le plat a supprimer"<<endl;
        cin>> nomPlat;
        m.SupprimerPlat(nomPlat);
    }
    if(choice=='6'){
        m.AfficherMenu();
        cout<<"Saisir le Boisson a supprimer"<<endl;
        cin>> nomPlat;
        m.SupprimerBoisson(nomPlat);
    }
}






















//GestiondeStock
void GestiondeStock(Stock &S){
    S.AfficherDetail();
    cout<<"Ajouter des ingredients au stock"<<endl;
    cout<<"a:Ajouter "<<" r:retour"<<endl;
    char choice;
    cin>>choice;
    if(choice=='a'){
        Ingredient i;
        cout<<"Nom d'ingredient:"<<endl;
        cin>>i.nom;
        cout<<"Quantite:"<<endl;
        cin>>i.Qte;
        S.AjouterIngredient(i);
    }
    else if(choice=='r'){
        exit;
    }
}






    
//Gestioncommande
void Gestioncommande(Commande &c,Stock &s,Menu &m,vector<Commande> &vco){
    
    cout<<"Gestion des commandes"<<endl;
    cout<<"MENU"<<endl;
    m.AfficherMenu();
    bool choi=true;
    while(choi){
    cout<<"1-Commander un plat"<<endl;
    cout<<"2-Commander un Boisson"<<endl;
    cout<<"3-retour"<<endl;
    char ch;
    cout<<"Saisir votre choix"<<endl;
    cin>>ch;
    

        
    if(ch=='1'){
        cout<<"1-Commander un plat"<<endl;   
        cout<<"Veuillez choisir le plat a commander"<<endl;
        int choixPlat;
        cin>>choixPlat;
        Plat PlatChoisie=(m.getListP())[choixPlat-1];
        for(int i=0;i<(PlatChoisie.LI()).size();i++){
            int qteIngr=(PlatChoisie.LI())[i].Qte;
                s.MAJ(PlatChoisie.LI()[i]);
                c.AjouterPlat(PlatChoisie);
                c.AfficherDetail();
        }
        
        
    } 
    
    else if(ch=='2'){
        cout<<"1-Commander un Boisson"<<endl;   
        cout<<"Veuillez choisir le Boisson a commander"<<endl;
        int choixBoi;
        cin>>choixBoi;
        Boisson BoissonChoisie=(m.getListB())[choixBoi-1];
        for(int i=0;i<(BoissonChoisie.LI()).size();i++){
            int qteIngr=BoissonChoisie.LI()[i].getQte();
                s.MAJ(BoissonChoisie.LI()[i]);
                c.AjouterBoisson(BoissonChoisie);
                c.AfficherDetail();
        }
        
    }
    
    else if(ch=='3'){
        choi=false;
    }
    
    cout<<"Total: "<<c.CalculerTotal()<<endl;
        
    }

}





//Getion des reservations
void GestionReservation(ListClient &LC, Client &c, vector<Reservation> &vr, Reservation &res) {
    
    cout << "Gestion des Reservations" << endl;
    cout << "------------------------" << endl;
    cout << "Saisir le nom de client" << endl;
    string n, dr, hr, nt;
    int nbrP;
    cin >> n;

    for (int i = 0; i < LC.getLC().size(); i++) {
        if (n == LC.getLC()[i].getnom()) {
            cout << "Listes des Reservations" << endl;
            for (int j = 0; j < LC.getLC()[i].LR().size(); j++) {
                cout << "Reservation " << j + 1 << endl;
                LC.getLC()[i].LR()[j].AfficherDetail();
                cout << "----------" << endl;
            }

            cout << "a:Ajouter une Reservation " << "r:Retour" << endl;
            char ch;
            cin >> ch;

            if (ch == 'a') {
                cout << "Saisir la date de Reservation" << endl;
                cin >> dr;
                cout << "Saisir l'Heure de Reservation" << endl;
                cin >> hr;
                cout << "Saisir le nbr de Personne" << endl;
                cin >> nbrP;
                res.setDate(dr);
                res.setHeure(hr);
                res.setNbrP(nbrP);
                vr.push_back(res);
                c.setnom(n);
                c.Reserver(res);
                LC.setClient(c);
                return;
            } else if (ch == 'r') {
                return; // return instead of exit
            }
        }
    }

    // If the client name was not found, ask for telephone number
    cout << "Saisir le numero de Telephone du client" << endl;
    cin >> nt;
    cout << "a:Ajouter une Reservation " << "r:Retour" << endl;
    char ch;
    cin >> ch;
    if (ch == 'a') {
        cout << "Saisir la date de Reservation" << endl;
        cin >> dr;
        cout << "Saisir l'Heure de Reservation" << endl;
        cin >> hr;
        cout << "Saisir le nbr de Personne" << endl;
        cin >> nbrP;
        res.setDate(dr);
        res.setHeure(hr);
        res.setNbrP(nbrP);
        vr.push_back(res);
        c.setnom(n);
        c.setNT(nt);
        c.Reserver(res);
        LC.ajouterClient(c);
        return;
    }
}
























//main

int main()
{
    Ingredient i1,i2,i3,i4,i5;
    i1.nom="Tomate";
    i1.Qte=100;
    i2.nom="Fromage";
    i2.Qte=120;
    i5.nom="Lait";
    i5.Qte=50;
    i3.nom="Fromage";
    i3.Qte=10;
    i4.nom="Lait";
    i4.Qte=1;
    vector<Ingredient> vi,vi2,vi3;
    vi.push_back(i1);
    vi.push_back(i2);
    vi.push_back(i5);
    vi2.push_back(i3);
    vi3.push_back(i4);
    Stock s(vi);
    Plat p1("fd","fdsgsdfs",23,vi2);
    Boisson b1("fdsg","gfdgfddfsaf",15,vi3);
    Reservation r("3/5/2024","20:00",3);
    vector<Reservation> vr;
    vr.push_back(r);
    Commande c;
    Client c1i("Ahmed","0653748392",vr);
    ListClient lc;
    lc.ajouterClient(c1i);
    vector<Commande> vc;
    Menu m;
    m.AjouterPlat(p1);
    m.AjouterBoisson(b1);
    while(bool q=true){
    int choix;
    cout<<"Menu General"<<endl;
    cout<<"1-Gestion Menu"<<endl;
    cout<<"2-Gestion des Reservations"<<endl;
    cout<<"3-Gestion des commandes"<<endl;
    cout<<"4-Gestion de stock"<<endl;
    cout<<"Choisir votre option"<<endl;
    cin>>choix;
    if(choix==4){
        GestiondeStock(s);
    }
    if(choix==1){
        GestiondeMenu(m,s);
    }
    if(choix==3){
        Gestioncommande(c,s,m,vc);
    }
    else if(choix==2){
        GestionReservation(lc,c1i,vr,r);
        }
    }
    
    
    return 0;
}
