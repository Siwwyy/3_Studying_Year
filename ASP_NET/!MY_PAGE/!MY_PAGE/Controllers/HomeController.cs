//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Web;
//using System.Web.Mvc;
//using _MY_PAGE.Models;

using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Microsoft.AspNet.Identity;
using _MY_PAGE.Models;

namespace _MY_PAGE.Controllers
{
    public class HomeController : Controller
    {
        //Users
        private ApplicationDbContext db = new ApplicationDbContext();

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult Dodaj_Ogloszenie(string nazwa_auta, string model_auta, string pochodzenie, string przebieg, string silnik, string cena, string fuel, string imie, string nazwisko)
        {
            ViewBag.Message = "Add your advertisement.";

            if (nazwa_auta != null)
            {
                Random rand = new Random(100);
                //string idik = generateID(); //popraw id
                Marka_Pojazdu Ha = new Marka_Pojazdu();
                //Ha.ID = int.Parse(generateID());
                Ha.ID = rand.Next(00000, 999999);
                Ha.Nazwa_Marka = nazwa_auta;
                db.Mark.Add(Ha);


                db.SaveChanges();
                Informacje_w_ogloszeniu Ha2 = new Informacje_w_ogloszeniu();
                Ha2.ID = rand.Next(00000, 999999);
                Ha2.Moc_Silnika = int.Parse(silnik);
                Ha2.Przebieg_do = int.Parse(przebieg);
                Ha2.Cena = int.Parse(cena);
                db.Info.Add(Ha2);
                db.SaveChanges();
                Kraj_Pochodzenia Ha3 = new Kraj_Pochodzenia();
                Ha3.ID = rand.Next(00000, 999999);
                Ha3.Nazwa_Kraj_Pochodzenia = pochodzenie;
                db.Country.Add(Ha3);

                db.SaveChanges();
                Sprzedawca Ha4 = new Sprzedawca();
                Ha4.ID = rand.Next(00000, 999999);
                Ha4.Imie = imie;
                Ha4.Nazwiska = nazwisko;
                Ha4.Pesel = rand.Next(00000, 999999);
                db.Seller.Add(Ha4);
                db.SaveChanges();
                Rodzaj_Paliwa Ha5 = new Rodzaj_Paliwa();
                Ha5.ID = rand.Next(00000, 999999);
                Ha5.Nazwa_Rodzaj = fuel;
                db.Fuel_Type.Add(Ha5);

                db.SaveChanges();

                Model_Pojazdu Ha1 = new Model_Pojazdu();
                Ha1.ID = rand.Next(00000, 999999);
                Ha1.Nazwa_Model = model_auta;
                Ha1.Marka_ID = Ha.ID;
                Ha1.Informations = Ha2;
                Ha1.Kraj_Pochodzenia_ID = Ha3.ID;
                Ha1.Rodzaj_Paliwa_ID = Ha5.ID;
                Ha1.Country_Of_Origin = Ha3;
                Ha1.Fuel_Type = Ha5;
                Ha1.Country_Of_Origin = Ha3;
                Ha1.Marka = Ha;
                Ha1.Seller = Ha4;
                Ha1.Sprzedawca_ID = Ha4.ID;
                db.Model.Add(Ha1);
                db.SaveChanges();
            }
            return View();
        }

        public ActionResult Wyszukaj_Ogloszenie()
        {
            ViewBag.Message = "Find your car";
            IList<Model_Pojazdu> modele = new List<Model_Pojazdu>(db.Model.ToList());
            ViewData["Advertisements"] = modele;
            return View();
        }

        ////Display Users
        //[HttpGet]
        public ActionResult Manage_Accounts_Admin()
        {
            ViewBag.Message = "Admin Panel";
            return View(db.Users.ToList());
        }

        [HttpPost]
        public ActionResult Delete_User(string id)
        {
            var User = db.Users.Find(id);
            db.Users.Remove(User);
            db.SaveChanges();
            return RedirectToAction("Index", "Home");
        }

        public string generateID()
        {
            var userId = User.Identity.GetUserId();
            return userId;
        }
    }
}