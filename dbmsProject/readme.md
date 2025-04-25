# SQL Query Runner

SQL Query Runner is a web-based application that allows users to execute SQL queries against MySQL and Oracle databases. It provides an intuitive interface for writing and running SQL scripts, viewing results, and managing database operations.

## Features

- **Dual Database Support**: Run queries against either MySQL or Oracle databases
- **SQL Script Library**: Organized collection of SQL scripts by category
- **Syntax Highlighting**: SQL code highlighting for better readability
- **Query Execution**: Run queries and view results in a tabular format
- **Database Operations**: Commit, rollback, show table structure, and view table content
- **Responsive Design**: Works on desktop and mobile devices

## Project Structure

```
fastapi-query-runner/
├── .env.local.example        # Environment variables template
├── .gitignore                # Git ignore configuration
├── Dockerfile                # Docker configuration
├── config.py                 # Database configuration
├── database.py               # Database connection handlers
├── main.py                   # FastAPI application
├── static/                   # Frontend static files
│   ├── index.html            # Main HTML page
│   ├── script.js             # Frontend JavaScript
│   ├── styles.css            # CSS styles
│   └── favicon.png           # Application icon
└── sql_scripts/              # SQL script files (organized by category)
```

## Setup and Installation

### Prerequisites

- Python 3.9 or higher
- MySQL database (Aiven Cloud or any other MySQL server)
- Oracle database (Optional)

### Environment Configuration

1. Copy the `.env.local.example` file to `.env.local`:
   ```
   cp .env.local.example .env.local
   ```

2. Update the `.env.local` file with your database credentials:
   ```
   pymysqldb=YOUR_PYMYSQL_DB
   pymysqlhost=YOUR_PROJECT.aivencloud.com
   pymysqlpassword=YOUR_SQL_PASSWORD
   user=YOUR_SQL_USER
   USER2=YOUR_ORACLE_USER_NAME
   PASS2=YOUR_ORACLE_PASSWORD
   DSN=YOUR_DSN
   ```

### Installation Options

#### Option 1: Running Locally

1. Install the required dependencies:
   ```
   pip install -r requirements.txt
   ```

2. Run the FastAPI application:
   ```
   uvicorn main:app --host 0.0.0.0 --port 8080
   ```

#### Option 2: Using Docker

1. Build the Docker image:
   ```
   docker build -t sql-query-runner .
   ```

2. Run the Docker container:
   ```
   docker run -p 8080:8080 --env-file .env.local sql-query-runner
   ```

#### Option 3: Deploying to Google Cloud Run

1. Make sure you have the [Google Cloud SDK](https://cloud.google.com/sdk/docs/install) installed and configured

2. Build the Docker image with Google Container Registry (GCR) tag:
   ```
   docker build -t gcr.io/YOUR-PROJECT-ID/fastapi-google-cloud .
   ```

3. Push the Docker image to Google Container Registry:
   ```
   docker push gcr.io/YOUR-PROJECT-ID/fastapi-google-cloud
   ```

4. Deploy the container to Google Cloud Run:
   ```
   gcloud run deploy SERVICE-NAME --image gcr.io/YOUR-PROJECT-ID/fastapi-google-cloud --platform managed --region YOUR-REGION --allow-unauthenticated
   ```

   Where:
   - `YOUR-PROJECT-ID` is your Google Cloud project ID
   - `SERVICE-NAME` is the name you want to give your service
   - `YOUR-REGION` is your preferred Google Cloud region (e.g., `asia-south2`, `us-central1`)

5. Access your application at the URL provided after deployment

**Note**: When deploying to Google Cloud Run, you'll need to set up your environment variables in the Google Cloud console or via the `gcloud` command instead of using the `.env.local` file. You can set environment variables with:

```
gcloud run services update SERVICE-NAME --set-env-vars="KEY1=VALUE1,KEY2=VALUE2"
```

### Accessing the Application

Once running, access the application at:
```
http://localhost:8080
```
Or at the URL provided by Google Cloud Run if deployed there.

## Usage Guide

### Running Queries

1. Select a database type (MySQL or Oracle) from the dropdown
2. Select a script category from the sidebar
3. Choose a specific SQL script file
4. Edit the query if needed
5. Click "Run Query" or press Ctrl+Enter to execute

### Common Operations

- **View Table**: Displays all records in a specified table
- **View Structure**: Shows the structure/schema of a specified table
- **Commit**: Commits the current transaction
- **Rollback**: Rolls back the current transaction
- **Drop Table**: Deletes a specified table (with confirmation)

### Adding Custom SQL Scripts

Add your own SQL scripts by placing them in the `sql_scripts` directory:

1. Create a category folder if it doesn't exist:
   ```
   mkdir -p sql_scripts/your_category
   ```

2. Add SQL files (with `.sql` extension) to the category folder:
   ```
   touch sql_scripts/your_category/your_script.sql
   ```

## Development

### Adding New Features

The application follows a clean separation between backend (FastAPI) and frontend:

- Backend logic is in `main.py`, `database.py`, and `config.py`
- Frontend logic is in the `static` directory

### Frontend Components

- **HTML**: The main interface structure (`static/index.html`)
- **CSS**: Styling and responsive design (`static/styles.css`)
- **JavaScript**: Client-side logic and API interaction (`static/script.js`)

### Backend API Endpoints

- `GET /`: Serves the main HTML page
- `GET /get-sql-scripts`: Returns available SQL script categories and files
- `GET /get-script-content/`: Retrieves the content of a specific SQL script
- `POST /execute-query`: Executes SQL queries and returns results

## Security Considerations

- Database credentials are stored in the `.env.local` file (excluded from Git)
- Input validation is performed on SQL queries
- HTML content is escaped to prevent XSS attacks
- When deployed to Google Cloud Run, use secure environment variable management
- Never share your Google Cloud project IDs or credentials in public repositories

## Credits

- SQL icon by [Icons8](https://icons8.com)
- Syntax highlighting by [Prism.js](https://prismjs.com/)
- Icons by [Font Awesome](https://fontawesome.com/)