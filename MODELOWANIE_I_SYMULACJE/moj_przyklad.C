#include <Riostream.h>
#include <fstream>
#include <math.h>

void projekt()
{
  Int_t n=99,i,j ;
  Float_t x1[3000];
  std::ifstream file;

   file.open("");
   for(i=0;i<3000;i=i+1)
     {
	  file>>x1[i];
     }
  file.close();

   TH1F *im1 = new TH1F("dane","sredni czas przejazdu trasa WZ",60, 0, 60);
    for(i=0;i<5000;i=i+1)
	{ 
		im1->Fill(x1[i]);
	}

TCanvas *canvas = new TCanvas("im1");

canvas->SetFillColor(0);
canvas->Divide(1,1); 


 canvas->cd(1);
 im1->SetFillColor(2);
 im1->SetFillStyle(3002);
 im1->Draw();

 
}