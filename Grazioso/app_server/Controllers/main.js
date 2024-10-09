/* GET Homepage */
const index = (req, res) => {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 4586d48 (enhancements to app_api and app_server)
    // Example of fetching data (replace with your actual logic)
    const featuredPets = [
      { name: 'Buddy', breed: 'Golden Retriever' },
      { name: 'Lucy', breed: 'Labrador' }
    ];
  
    res.render('index', { 
      title: 'Pet Rescue', 
      featuredPets: featuredPets // Pass data to the view
    });
  };
  
  module.exports = { 
    index 
  };
<<<<<<< HEAD
  
=======
    res.render('index', { title: 'Pet Rescue' });
};

module.exports = { index;
}
>>>>>>> 2084a8e (app_server update)
=======
  
>>>>>>> 4586d48 (enhancements to app_api and app_server)
