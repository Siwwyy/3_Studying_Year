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
    public class Informacje_w_ogloszeniuController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Informacje_w_ogloszeniu
        public ActionResult Index()
        {
            return View(db.Info.ToList());
        }

        // GET: Informacje_w_ogloszeniu/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Informacje_w_ogloszeniu informacje_w_ogloszeniu = db.Info.Find(id);
            if (informacje_w_ogloszeniu == null)
            {
                return HttpNotFound();
            }
            return View(informacje_w_ogloszeniu);
        }

        // GET: Informacje_w_ogloszeniu/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Informacje_w_ogloszeniu/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Model_ID,Cena,Przebieg_od,Przebieg_do,Moc_Silnika")] Informacje_w_ogloszeniu informacje_w_ogloszeniu)
        {
            if (ModelState.IsValid)
            {
                db.Info.Add(informacje_w_ogloszeniu);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(informacje_w_ogloszeniu);
        }

        // GET: Informacje_w_ogloszeniu/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Informacje_w_ogloszeniu informacje_w_ogloszeniu = db.Info.Find(id);
            if (informacje_w_ogloszeniu == null)
            {
                return HttpNotFound();
            }
            return View(informacje_w_ogloszeniu);
        }

        // POST: Informacje_w_ogloszeniu/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Model_ID,Cena,Przebieg_od,Przebieg_do,Moc_Silnika")] Informacje_w_ogloszeniu informacje_w_ogloszeniu)
        {
            if (ModelState.IsValid)
            {
                db.Entry(informacje_w_ogloszeniu).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(informacje_w_ogloszeniu);
        }

        // GET: Informacje_w_ogloszeniu/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Informacje_w_ogloszeniu informacje_w_ogloszeniu = db.Info.Find(id);
            if (informacje_w_ogloszeniu == null)
            {
                return HttpNotFound();
            }
            return View(informacje_w_ogloszeniu);
        }

        // POST: Informacje_w_ogloszeniu/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Informacje_w_ogloszeniu informacje_w_ogloszeniu = db.Info.Find(id);
            db.Info.Remove(informacje_w_ogloszeniu);
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
