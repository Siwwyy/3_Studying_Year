using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using _MY_PAGE.Models;


namespace _MY_PAGE.Controllers
{
    public class Model_PojazduController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();
      //  public ViewDataDictionary ViewData = new ViewDataDictionary();
        // GET: Model_Pojazdu
        public ActionResult Index()
        {
            return View(db.Model.ToList());
        }


        [HttpPost]
        public List<string> Index(Marka_Pojazdu model)
        {
            List<string> my_list = null;
            //if (model.Nazwa_Marka != null)
            //{
            //    foreach (var marka in model.Nazwa_Marka)
            //    {
            //        my_list.Add(marka.ToString());
            //        //marka.Selected = true;
            //        //ViewBag.Message += marka.Text + " | ";
            //    }
            //}
            return my_list;
        }

        // GET: Model_Pojazdu/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Model_Pojazdu model_Pojazdu = db.Model.Find(id);
            if (model_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(model_Pojazdu);
        }

        // GET: Model_Pojazdu/Create
        public ActionResult Create()
        {
            IList<Marka_Pojazdu> marki = new List<Marka_Pojazdu>(db.Mark.ToList());

            ViewData["Mark"] = marki;
            return View();
        }

        // POST: Model_Pojazdu/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Marka_ID,Kraj_Pochodzenia_ID,Sprzedawca_ID,Rodzaj_Paliwa_ID,Nazwa_Model")] Model_Pojazdu model_Pojazdu)
        {
            if (ModelState.IsValid)
            {
                db.Model.Add(model_Pojazdu);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(model_Pojazdu);
        }

        // GET: Model_Pojazdu/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Model_Pojazdu model_Pojazdu = db.Model.Find(id);
            if (model_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(model_Pojazdu);
        }

        // POST: Model_Pojazdu/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Marka_ID,Kraj_Pochodzenia_ID,Sprzedawca_ID,Rodzaj_Paliwa_ID,Nazwa_Model")] Model_Pojazdu model_Pojazdu)
        {
            if (ModelState.IsValid)
            {
                db.Entry(model_Pojazdu).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(model_Pojazdu);
        }

        // GET: Model_Pojazdu/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Model_Pojazdu model_Pojazdu = db.Model.Find(id);
            if (model_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(model_Pojazdu);
        }

        // POST: Model_Pojazdu/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Model_Pojazdu model_Pojazdu = db.Model.Find(id);
            db.Model.Remove(model_Pojazdu);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
