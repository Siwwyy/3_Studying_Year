#include <iostream>
#include <fstream>
#include <cmath>

void moj_przyklad()
{
	using namespace std;
  Int_t n=3000;
  Float_t x1[3000];
  std::ifstream file;

   file.open("E:\\!!Projects VS\\!!!3_Studying_Year\\3_Studying_Year\\MODELOWANIE_I_SYMULACJE\\Main_Project\\Main_Project\\file.out");
   for(int i=0;i<3000;i=i+1)
     {
	  file>>x1[i];
     }
  file.close();

TH1F *h = new TH1F("h","sredni czas przejazdu trasa WZ",60, 0, 60);
   h->SetMaximum(180);

   for (int i=0;i<3000;i++)
   {
      h->Fill(x1[i]);
   }

   Double_t par[9];
   TF1 *g1    = new TF1("g1","gaus",10,25);
   TF1 *g2    = new TF1("g2","gaus",30,40);
   TF1 *g3    = new TF1("g3","gaus",45,60);
   TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)",0,60);
   total->SetLineColor(2);
   h->Fit(g1,"R");
   h->Fit(g2,"R+");
   h->Fit(g3,"R+");
   g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]);
   g3->GetParameters(&par[6]);
   total->SetParameters(par);
   
   TCanvas *canvas = new TCanvas("h");
   canvas->SetFillColor(0);
   canvas->Divide(1,1);
   canvas->cd(1);
   h->SetFillColor(2);
   h->SetFillStyle(3002);
   
   h->Fit(total,"R+"); 
}