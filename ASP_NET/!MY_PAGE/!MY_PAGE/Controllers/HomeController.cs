using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace _MY_PAGE.Controllers
{
    public class HomeController : Controller
    {
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

        public ActionResult Dodaj_Ogloszenie()
        {
            ViewBag.Message = "Add your advertisement.";

            return View();
        }

        public ActionResult Wyszukaj_Ogloszenie()
        {
            ViewBag.Message = "Find your car";

            return View();
        }
    }
}