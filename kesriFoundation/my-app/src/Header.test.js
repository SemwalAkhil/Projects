// src/Header.test.js
import { render, screen } from '@testing-library/react';
import Header from './Header';

test('renders header', () => {
  render(<Header />);
  const headerElement = screen.getByText(/My React App/i);
  expect(headerElement).toBeInTheDocument();
});
