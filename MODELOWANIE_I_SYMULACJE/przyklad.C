#include <iostream>
#include <fstream>
#include <cmath>

void przyklad()
{
using namespace std;

  // wczytanie danych

  Int_t n=1000,i,j ;

 Float_t x1[n],x2[n],x3[n],x4[n],x5[n],x6[n], y1;

  ifstream d;
 // ifstream d2;

  // d.open("density");
   // pod windows
      d.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\Generating\\Generating\\file.out");
      //d.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\4_rodzaje_losowan\\4_rodzaje_losowan\\file.out");
      //d2.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\4_rodzaje_losowan\\4_rodzaje_losowan\\file_2.out");
      //d2.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\4_rodzaje_losowan\\4_rodzaje_losowan\\file_2.out");

   for(i=0;i<n;i=i+1)
     {
       d>>x1[i];
       //d2>>x2[i];

// operacje na danych

         //x6[i]=x1[i]+8.*x4[i];


      }
   d.close();

   // deklarowanie histogramu "jednowymiarowego"  .... liczba klas, przedział

   TH1F *im1 = new TH1F("im1"," First ", 30,-0.5,20.5);
   TH1F *im2 = new TH1F("im2"," Second ",100,-1.,1.);


   TH2F *imd2 = new TH2F("imd2","jestem histogramem-2wym ",0.0,0.,2.0,0.0,0.,2.0);

      for(i=0;i<n;i=i+1)
        { 
	  im1->Fill(x1[i]);
	  //im2->Fill(x2[i]);
	}
   // for(j=0;j<n;j=j+1)
   //   {
        //  imd2->Fill(x1[j],x1[j]);
	//}
         
    //skalowanie histogramu

          //float scale_const=0.001;
           //im1->Scale(scale_const);
    
	
    ///stworzenie canwy do rysunku
TCanvas *test = new TCanvas("test","test");
test->SetFillColor(0);
// podzial na 2 pady
test->Divide(2,1); 
// przejscie do pada z niumerem 2
 test->cd(1);

         im2->Draw();

      TH1F im3=8.* (*im2);

      // opcje rysowania histogramu
   im1->SetFillColor(2);
   im1->SetFillStyle(3002);
 test->cd(2);
         im1->Draw();
	 // narysowanie dwoch histogramowna jednym rysunku
	 im2->Draw("same");


	 // nowa canwa do rysowania

TCanvas *test2 = new TCanvas("test2","test2");
// tlo biale ?? 
test2->SetFillColor(0);
//dzielenie na pady


//cos na temat statystyki
//ok np gStyle->SetOptStat(111);
test2->Divide(2,2); 
 test2->cd(1);
 // opcje draw : lego, box, cont4z
        imd2->Draw();

	test2->cd(2);
        imd2->Draw("lego");

	test2->cd(3);
        imd2->Draw("box");

	test2->cd(4);
        imd2->Draw("cont4z");


//tworzenie graphu bez bledow z n punków, x1, x2 tablice dla wspolrzednych z i y


TGraph *gr3 =new TGraph(n,x1,x2);

// opcje wykresu lini(typ, kolor, grybosc lini) i punktow(typ wielkosc) 

 gr3->SetLineColor(kBlue);
 gr3->SetLineWidth(2);
 gr3->SetLineStyle(1);

  gr3->SetMarkerColor(3);
  //gr3->SetMarkerStyle(21),
  //gr3->SetMarkerSize(2);

 //rysowanie na domyslnej canwie– A aby były osie; L polaczone linią; P – zazanczone punkty
TCanvas *test3 = new TCanvas("test3","test3");
test->SetFillColor(0);

  gr3->Draw("ALP");
  // definiowanie funcji do dopasowania
TF1 *ff = new TF1("ff","[0]+[1]*x-[2]*pow(x,2)",40.,80.);
  gr3->Fit(ff);


  
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
