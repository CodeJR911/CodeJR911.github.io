/* GET pet view */
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 4586d48 (enhancements to app_api and app_server)
const pet = (req, res) => {
    // Example pet data (replace with database or API call)
    const petData = {
      name: 'Buddy',
      species: 'Dog',
      breed: 'Golden Retriever',
      age: 2,
      imageUrl: 'https://example.com/dog.jpg',
      description: 'A friendly and playful dog.',
    };
  
    res.render('pet', { title: 'Pet Rescue', pet: petData });
  };
  
  module.exports = { 
    pet 
  };
<<<<<<< HEAD
  
=======
const travel = (req, res) => {
    res.render('pet', { title: 'Pet Rescue' });
};

module.exports = { 
    pet
};
>>>>>>> 2084a8e (app_server update)
=======
  
>>>>>>> 4586d48 (enhancements to app_api and app_server)
