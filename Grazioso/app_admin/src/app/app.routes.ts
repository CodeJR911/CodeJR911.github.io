import { Routes } from '@angular/router';
import { PetListingComponent } from './pet-listing/pet-listing.component';
import { AddPetComponent } from './add-pet/add-pet.component';

export const routes: Routes = [
  { path: '', redirectTo: '/pets', pathMatch: 'full' }, // Redirect to /pets by default
  { path: 'pets', component: PetListingComponent },
  { path: 'add-pet', component: AddPetComponent }
];
