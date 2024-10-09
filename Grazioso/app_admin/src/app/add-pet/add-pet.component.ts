import { Component } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { PetDataService } from '../services/pet-data.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-add-pet',
  standalone: true,
  imports: [],
  templateUrl: './add-pet.component.html',
  styleUrl: './add-pet.component.css'
})
export class AddPetComponent {
  petForm: FormGroup;

  constructor(
    private fb: FormBuilder,
    private petDataService: PetDataService,
    private router: Router
  ) {
    this.petForm = this.fb.group({
      name: ['', Validators.required],
      species: ['', Validators.required],
      breed: [''],
      age: ['', [Validators.required, Validators.min(0)]],
      imageUrl: [''],
      description: [''],
      adoptionStatus: ['Available'] // Default to 'Available'
    });
  }

  onSubmit() {
    if (this.petForm.valid) {
      const petData = this.petForm.value;
      this.petDataService.addPet(petData).subscribe(
        () => {
          // Handle successful submission
          console.log('Pet added successfully!');
          this.router.navigate(['/pets']); // Navigate to the pet listing
        },
        (error) => {
          // Handle errors
          console.error('Error adding pet:', error);
        }
      );
    }
  }
}
