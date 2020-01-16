#include <iostream>
#include <fstream>
#include <cmath>

void przyklad()
{
using namespace std;

  // wczytanie danych

  Int_t n=2000,i,j ;

 Float_t x1[n],x2[n],x3[n],x4[n],x5[n],x6[n], y1;

  ifstream d;
  //ifstream d2;

  // d.open("density");
   // pod windows
   d.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\Main_Project\\Main_Project\\Auto.txt");
      //d.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\4_rodzaje_losowan\\4_rodzaje_losowan\\file.out");
     // d2.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\Rozklad_Poissona\\Rozklad_Poissona\\out2.out");
      //d2.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\4_rodzaje_losowan\\4_rodzaje_losowan\\file_2.out");

   for(i=0;i<n;i=i+1)
     {
       d>>x1[i];
       //d2>>x2[i];

// operacje na danych

         //x6[i]=x1[i]+8.*x4[i];


      }
   d.close();
 //  d2.close();
i = 0;
   // deklarowanie histogramu "jednowymiarowego"  .... liczba klas, przedział

   TH1F *h = new TH1F("Auto"," Roczny Koszt Utrzymania Samochodu ", 10000,1000.0,22000.0);
  // TH1F *im2 = new TH1F("im2"," Second ",5000,0.0,1000.0);
   h->SetMaximum(6);


   // TH2F *imd2 = new TH2F("imd2","jestem histogramem-2wym ",0.0,0.,2.0,0.0,0.,2.0);

      for(i=0;i<n;i=i+1)
        { 
		//im1->Fill(x1[i]+x2[i]);
		h->Fill(x1[i]);
	}
   // for(j=0;j<n;j=j+1)
   //   {
        //  imd2->Fill(x1[j],x1[j]);
	//}
         
    //skalowanie histogramu

          //float scale_const=0.001;
           //im1->Scale(scale_const);
    
	
   Double_t par[44];
   TF1 *g1    = new TF1("g1","gaus",0,2000);
   TF1 *g2    = new TF1("g2","gaus",3000,5000);
   TF1 *g3    = new TF1("g3","gaus",6000,9000);
   TF1 *g4   = new TF1("g4","gaus",13000,17000);
   TF1 *g5   = new TF1("g5","gaus",18000,22000);
   TF1 *total = new TF1("total","gaus(0)+gaus(5)+gaus(10)+gaus(20)+gaus(40)",0,22000);
   total->SetLineColor(2);
   h->Fit(g1,"R+");
   h->Fit(g2,"R+");
   h->Fit(g3,"R+");
   h->Fit(g4,"R+");
   h->Fit(g5,"R+");
   g1->GetParameters(&par[0]);
   g2->GetParameters(&par[5]);
   g3->GetParameters(&par[10]);
   g4->GetParameters(&par[20]);
   g5->GetParameters(&par[40]);
   total->SetParameters(par);
   
   TCanvas *canvas = new TCanvas("h");
   canvas->SetFillColor(0);
   canvas->Divide(1,1);
   canvas->cd(1);
   h->SetFillColor(2);
   h->SetFillStyle(3002);
   
   h->Fit(total,"R+"); 

      // opcje rysowania histogramu
   // im1->SetFillColor(1);
   // im1->SetFillStyle(3002);
 // test->cd(2);
         // im1->Draw();
	 // narysowanie dwoch histogramowna jednym rysunku
	// im2->Draw("same");


	 // // nowa canwa do rysowania

// TCanvas *test2 = new TCanvas("test2","test2");
// // tlo biale ?? 
// test2->SetFillColor(0);
// //dzielenie na pady


// //cos na temat statystyki
// //ok np gStyle->SetOptStat(111);
// test2->Divide(2,2); 
 // test2->cd(1);
 // // opcje draw : lego, box, cont4z
        // imd2->Draw();

	// test2->cd(2);
        // imd2->Draw("lego");

	// test2->cd(3);
        // imd2->Draw("box");

	// test2->cd(4);
        // imd2->Draw("cont4z");


// //tworzenie graphu bez bledow z n punków, x1, x2 tablice dla wspolrzednych z i y


// TGraph *gr3 =new TGraph(n,x1,x2);

// // opcje wykresu lini(typ, kolor, grybosc lini) i punktow(typ wielkosc) 

 // gr3->SetLineColor(kBlue);
 // gr3->SetLineWidth(2);
 // gr3->SetLineStyle(1);

  // gr3->SetMarkerColor(3);
  // //gr3->SetMarkerStyle(21),
  // //gr3->SetMarkerSize(2);

 // //rysowanie na domyslnej canwie– A aby były osie; L polaczone linią; P – zazanczone punkty
// TCanvas *test3 = new TCanvas("test3","test3");
// test->SetFillColor(0);

  // gr3->Draw("ALP");
  // // definiowanie funcji do dopasowania
// TF1 *ff = new TF1("ff","[0]+[1]*x-[2]*pow(x,2)",40.,80.);
  // gr3->Fit(ff);


  
}
  /*
//tworzenie wykresow z bledami
  Float_t erx[80];
  for(Int_t i=0;i<n;i++){erx[i]=0.;}

TGraph *gr =new TgraphErrors(n,x1,x2,erx,x3);

 gr->SetLineColor(1);
 gr->SetMarkerColor(1);
 gr->SetMarkerStyle(3),
 gr->SetMarkerSize(2);
 gr->SetLineStyle(1);
 gr->SetLineWidth(2);
  gr->Draw("ALP");


//Opcje Draw()
//Draw(ap) - os i punkty"
 gr->Draw("Ap");

//Draw(al) - os i laczenie punktow odcinkami
 gr1->Draw("Al");

//Draw(alp)-os, punkty oraz laczenie punktow odcinkami
 gr2->Draw("Alp");

//Draw(acp) - os, punkty oraz z interpolacja typu cubic spline
 gr4->Draw("Acp");


//Dopasowywanie funkcji do danych ( fitowanie)
//def funkcji do fitowania
TF1 *ff1 = new TF1("ff1","[0]*pow(x,[1])*exp(-[2]*x)",0,1000);

// ustalenie parametrów - w tej byly trzy parametry, to nie jest zawsze konieczne
// ff1->SetParameters(0.1,2.,0.01);

 //fitowane obiektu o nazwie gr1
gr1->Fit(ff1);
}
*/
